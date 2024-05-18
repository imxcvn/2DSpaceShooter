#include "Includes.h"

PlayScene::PlayScene(float width, float height) {

	if (!font.loadFromFile("Font/ARCADE.ttf")) {
		std::cout << "Nie ma czcionki." << std::endl;
	}
	score = 0;
	playerScore.setFont(font);
	playerScore.setFillColor(sf::Color::White);
	playerScore.setCharacterSize(70);
	playerScore.setString(std::to_string(score));
	playerScore.setPosition(15, 2.5);

	if (!heartsTexture.loadFromFile("Texture/3hearts.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	hearts.setTexture(heartsTexture);
	sf::Vector2u textureSize = heartsTexture.getSize();
	float sizeX = 150.f;
	float sizeY = 50.f;
	float scaleX = sizeX / textureSize.x;
	float scaleY = sizeY / textureSize.y;
	hearts.setScale(scaleX, scaleY);
	hearts.setPosition(660, 10);

	background.setSize(sf::Vector2f(820, 940));
	mainTexture.loadFromFile("Texture/SpaceBackground4.png");
	background.setTexture(&mainTexture);

	backgroundStars.setSize(sf::Vector2f(820, 940));
	starTexture.loadFromFile("Texture/stars4.png");
	backgroundStars.setTexture(&starTexture);

	backgroundStars2.setSize(sf::Vector2f(820, 940));
	starTexture2.loadFromFile("Texture/stars5.png");
	backgroundStars2.setTexture(&starTexture2);

	Projectile* object = new Projectile{ Game::instance };
	EnemyProjectile* projectile = new EnemyProjectile{ Game::instance };
	EnemySpaceship* enemy = new EnemySpaceship{ Game::instance };

	objects.push_back(object);
	projectiles.push_back(projectile);
	enemies.push_back(enemy);
	spaceShip = new SpaceShip{ Game::instance };
	spaceShip->setPosition(300, 650);
	
}

void PlayScene::render(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(backgroundStars);
	window.draw(backgroundStars2);
	window.draw(playerScore);
	window.draw(hearts);
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->render(window);
	}
	for (int i = 0; i < projectiles.size(); i++) {
		projectiles[i]->render(window);
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->render(window);
	}
	spaceShip->render(window);
}

bool PlayScene::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			Game::instance->changeScene(Game::instance->mainMenuScene);
			return true;
		}
		if (event.key.code == sf::Keyboard::Space) {
			Projectile* object = new Projectile{ Game::instance };
			objects.push_back(object);
		}
		if (event.key.code == sf::Keyboard::B) {
			EnemyProjectile* eProjectile = new EnemyProjectile{ Game::instance };
			projectiles.push_back(eProjectile);
			EnemySpaceship* spaceship = new EnemySpaceship{ Game::instance };
			enemies.push_back(spaceship);
		}
	}
	if (enemySpawnClock.getElapsedTime().asSeconds() >= 1.0f) {
		EnemyProjectile* eProjectile = new EnemyProjectile{ Game::instance };
		projectiles.push_back(eProjectile);
		EnemySpaceship* spaceship = new EnemySpaceship{ Game::instance };
		enemies.push_back(spaceship);
		enemySpawnClock.restart();
	}
	return false;
}

void PlayScene::clear() {
	for (int i = 0; i < objects.size(); i++) {
		delete objects[i];
	}
	objects.clear();
	for (int i = 0; i < projectiles.size(); i++) {
		delete projectiles[i];
	}
	projectiles.clear();
	for (int i = 0; i < enemies.size(); i++) {
		delete enemies[i];
	}
	enemies.clear();
	delete spaceShip;
}

void PlayScene::shown() {
	clear();
	spaceShip = new SpaceShip{ Game::instance };
	score = 0;
	playerScore.setString(std::to_string(score));
}

void PlayScene::update(float elapsed) {
	for (int i = 0; i < objects.size(); ) {
		objects[i]->update(elapsed);
		if (objects[i]->getShouldBeDestroyed()) {
			objects.erase(objects.begin() + i);
		}
		else
			i++;
	}
	for (int i = 0; i < projectiles.size(); ) {
		projectiles[i]->update(elapsed);
		if (projectiles[i]->getShouldBeDestroyed()) {
			projectiles.erase(projectiles.begin() + i);
		}
		else
			i++;
	}
	for (int i = 0; i < enemies.size(); ) {
		enemies[i]->update(elapsed);
		if (enemies[i]->getShouldBeDestroyed()) {
			enemies.erase(enemies.begin() + i);
		}
		else
			i++;
	}
	spaceShip->update(elapsed);
	for (int i = 0; i < objects.size(); ) {
		sf::Rect<float> pBounds = objects[i]->getGlobalBounds();
		bool destroyed = false;
		for (int j = 0; j < enemies.size(); j++) {
			sf::Rect<float> eBounds = enemies[j]->getGlobalBounds();
			if (pBounds.intersects(eBounds)) {
				objects.erase(objects.begin() + i);
				enemies.erase(enemies.begin() + j);
				score += enemies[j]->getScore();
				playerScore.setString(std::to_string(score));
				Game::instance->setScore(score);
				destroyed = true;
				break;
			} 
		}
		if (destroyed == false) {
			i++;
		}
	}
	
}

PlayScene::~PlayScene() {
	clear();
}