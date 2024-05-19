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

	hearts.setTexture(Graphics::instance->threeHearts);
	sf::Vector2u textureSize = Graphics::instance->threeHearts.getSize();
	sizeX = 150.f;
	sizeY = 50.f;
	scaleX = sizeX / textureSize.x;
	scaleY = sizeY / textureSize.y;
	hearts.setScale(scaleX, scaleY);
	hearts.setPosition(660, 10);

	background.setSize(sf::Vector2f(820, 940));
	mainTexture.loadFromFile("Texture/SpaceBackground2.png");
	background.setTexture(&mainTexture);

	/*Projectile* object = new Projectile{ Game::instance };
	EnemyProjectile* projectile = new EnemyProjectile{ Game::instance };
	EnemySpaceship* enemy = new EnemySpaceship{ Game::instance };
	Asteroid* asteroid = new Asteroid{ Game::instance };

	asteroids.push_back(asteroid);
	objects.push_back(object);
	projectiles.push_back(projectile);
	enemies.push_back(enemy);*/
	/*spaceShip = new SpaceShip{ Game::instance };
	spaceShip->setPosition(300, 650);*/
	
}

void PlayScene::render(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(playerScore);
	window.draw(hearts);
	for (int i = 0; i < asteroids.size(); i++) {
		asteroids[i]->render(window);
	}
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
		/*if (event.key.code == sf::Keyboard::B) {
			EnemyProjectile* eProjectile = new EnemyProjectile{ Game::instance };
			projectiles.push_back(eProjectile);
			EnemySpaceship* spaceship = new EnemySpaceship{ Game::instance };
			enemies.push_back(spaceship);
		}*/
	}
	if (enemySpawnClock.getElapsedTime().asSeconds() >= 1.0f) {
		Asteroid* asteroid = new Asteroid{ Game::instance };
		asteroids.push_back(asteroid);
		EnemySpaceship* spaceship = new EnemySpaceship{ Game::instance };
		enemies.push_back(spaceship);
		Game::instance->setEnemyPosition(spaceship->getPositionX(), spaceship->getPositionY());
		/*if (projectileSpawnClock.getElapsedTime().asMilliseconds() >= 10.0f) {
			EnemyProjectile* eProjectile = new EnemyProjectile{ Game::instance };
			eProjectile->setDamage(spaceship->getDamage());
			projectiles.push_back(eProjectile);
			projectileSpawnClock.restart();
		}*/
		
		enemySpawnClock.restart();
	}
	return false;
}

void PlayScene::addEnemyProjectile(EnemyProjectile* projectile) {
	projectiles.push_back(projectile);
}

void PlayScene::clear() {
	for (int i = 0; i < objects.size(); i++) {
		delete objects[i];
	}
	objects.clear();
	for (int i = 0; i < asteroids.size(); i++) {
		delete asteroids[i];
	}
	asteroids.clear();
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
	hearts.setTexture(Graphics::instance->threeHearts);
	sf::Vector2u textureSize = Graphics::instance->threeHearts.getSize();
	sizeX = 150.f;
	sizeY = 50.f;
	scaleX = sizeX / textureSize.x;
	scaleY = sizeY / textureSize.y;
	hearts.setScale(scaleX, scaleY);
	hearts.setPosition(660, 10);
}

void PlayScene::update(float elapsed) {
	for (int i = 0; i < asteroids.size(); ) {
		asteroids[i]->update(elapsed);
		if (asteroids[i]->getShouldBeDestroyed()) {
			asteroids.erase(asteroids.begin() + i);
		}
		else
			i++;
	}
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
				score += enemies[j]->getScore();
				delete enemies[j];
				delete objects[i];
				objects.erase(objects.begin() + i);
				enemies.erase(enemies.begin() + j);
				playerScore.setString(std::to_string(score));
				if (score >= Game::instance->getScore()) {

					Game::instance->setScore(score);
				}
				destroyed = true;
				break;
			} 
		}
		if (destroyed == false) {
			i++;
		}
	}


	for (int i = 0; i < asteroids.size(); ) {
		sf::Rect<float> aBounds = asteroids[i]->getGlobalBounds();
		bool destroyed = false;
		sf::Rect<float> sBounds = spaceShip->getGlobalBounds();
		if (aBounds.intersects(sBounds)) {
			spaceShip->decreaseHealth(asteroids[i]->getDamage());
			delete asteroids[i];
			asteroids.erase(asteroids.begin() + i);

			if (spaceShip->getHpPoints() == 0) {
				Game::instance->changeScene(Game::instance->mainMenuScene);
				destroyed = true;
				break;
			}
			else if (spaceShip->getHpPoints() == 1) {
				hearts.setTexture(Graphics::instance->oneHeart);
				sf::Vector2u textureSize = Graphics::instance->oneHeart.getSize();
				sizeX = 50.f;
				sizeY = 50.f;
				scaleX = sizeX / textureSize.x;
				scaleY = sizeY / textureSize.y;
				hearts.setScale(scaleX, scaleY);
				hearts.setPosition(660, 10);
			}
			else if (spaceShip->getHpPoints() == 2) {
				hearts.setTexture(Graphics::instance->twoHearts);
				sf::Vector2u textureSize = Graphics::instance->twoHearts.getSize();
				sizeX = 100.f;
				sizeY = 50.f;
				scaleX = sizeX / textureSize.x;
				scaleY = sizeY / textureSize.y;
				hearts.setScale(scaleX, scaleY);
				hearts.setPosition(660, 10);
			}
		}
		if (destroyed == false) {
			i++;
		}
	}


	for (int i = 0; i < projectiles.size(); ) {
		sf::Rect<float> eBounds = projectiles[i]->getGlobalBounds();
		bool destroyed = false;
		sf::Rect<float> sBounds = spaceShip->getGlobalBounds();
		if (eBounds.intersects(sBounds)) {
			spaceShip->decreaseHealth(projectiles[i]->getDamage());
			delete projectiles[i];
			projectiles.erase(projectiles.begin() + i);
			if (spaceShip->getHpPoints() == 0) {
				Game::instance->changeScene(Game::instance->mainMenuScene);
				destroyed = true;
				break;
			}
			else if (spaceShip->getHpPoints() == 1) {
				hearts.setTexture(Graphics::instance->oneHeart);
				sf::Vector2u textureSize = Graphics::instance->oneHeart.getSize();
				sizeX = 50.f;
				sizeY = 50.f;
				scaleX = sizeX / textureSize.x;
				scaleY = sizeY / textureSize.y;
				hearts.setScale(scaleX, scaleY);
				hearts.setPosition(660, 10);
			}
			else if (spaceShip->getHpPoints() == 2) {
				hearts.setTexture(Graphics::instance->twoHearts);
				sf::Vector2u textureSize = Graphics::instance->twoHearts.getSize();
				sizeX = 100.f;
				sizeY = 50.f;
				scaleX = sizeX / textureSize.x;
				scaleY = sizeY / textureSize.y;
				hearts.setScale(scaleX, scaleY);
				hearts.setPosition(660, 10);
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