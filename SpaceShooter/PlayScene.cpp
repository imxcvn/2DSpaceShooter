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

	Graphics::setBgTexture(background, Graphics::instance->playScreenTexture);
	endSound.setBuffer(Graphics::instance->endBuffer);
	enemySound.setBuffer(Graphics::instance->enemyBuffer);
	playerSound.setBuffer(Graphics::instance->playerBuffer);
	scoreSound.setBuffer(Graphics::instance->scoreBuffer);
	shootSound.setBuffer(Graphics::instance->shootBuffer);
	shootSound.setVolume(20.f);
}

void PlayScene::render(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(playerScore);
	window.draw(hearts);
	for (int i = 0; i < asteroids.size(); i++) {
		asteroids[i]->render(window);
	}
	for (int i = 0; i < smallAsteroids.size(); i++) {
		smallAsteroids[i]->render(window);
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
			playerSound.play();
		}
	}
	if (enemySpawnClock.getElapsedTime().asSeconds() >= 1.0f) {
		Asteroid* asteroid = new Asteroid{ Game::instance };
		asteroids.push_back(asteroid);
		SmallAsteroid* sAsteroid = new SmallAsteroid{ Game::instance };
		smallAsteroids.push_back(sAsteroid);
		EnemySpaceship* spaceship = new EnemySpaceship{ Game::instance };
		enemies.push_back(spaceship);
		Game::instance->setEnemyPosition(spaceship->getPositionX(), spaceship->getPositionY());
		enemySpawnClock.restart();
	}
	return false;
}

void PlayScene::addEnemyProjectile(EnemyProjectile* projectile) {
	projectiles.push_back(projectile);
	enemySound.play();
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
	for (int i = 0; i < smallAsteroids.size(); i++) {
		delete smallAsteroids[i];
	}
	smallAsteroids.clear();
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

void PlayScene::updateHearts(int hpPoints, sf::Sprite& hearts) {
	if (hpPoints == 1) {
		hearts.setTexture(Graphics::instance->oneHeart);
		sf::Vector2u textureSize = Graphics::instance->oneHeart.getSize();
		hearts.setScale(50.f / textureSize.x, 50.f / textureSize.y);
		hearts.setPosition(760, 10);
		shootSound.play();
	}
	else if (hpPoints == 2) {
		hearts.setTexture(Graphics::instance->twoHearts);
		sf::Vector2u textureSize = Graphics::instance->twoHearts.getSize();
		hearts.setScale(100.f / textureSize.x, 50.f / textureSize.y);
		hearts.setPosition(710, 10);
		shootSound.play();
	}
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
	for (int i = 0; i < smallAsteroids.size(); ) {
		smallAsteroids[i]->update(elapsed);
		if (smallAsteroids[i]->getShouldBeDestroyed()) {
			smallAsteroids.erase(smallAsteroids.begin() + i);
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
				scoreSound.play();
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
				endSound.play();
				Game::instance->changeScene(Game::instance->mainMenuScene);
				destroyed = true;
				break;
			}
			else {
				updateHearts(spaceShip->getHpPoints(), hearts);
			}
			
		}
		if (destroyed == false) {
			i++;
		}
	}

	for (int i = 0; i < smallAsteroids.size(); ) {
		sf::Rect<float> aBounds = smallAsteroids[i]->getGlobalBounds();
		bool destroyed = false;
		sf::Rect<float> sBounds = spaceShip->getGlobalBounds();
		if (aBounds.intersects(sBounds)) {
			spaceShip->decreaseHealth(smallAsteroids[i]->getDamage());
			delete smallAsteroids[i];
			smallAsteroids.erase(smallAsteroids.begin() + i);
			if (spaceShip->getHpPoints() == 0) {
				endSound.play();
				Game::instance->changeScene(Game::instance->mainMenuScene);
				destroyed = true;
				break;
			}
			else {
				updateHearts(spaceShip->getHpPoints(), hearts);
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
				endSound.play();
				Game::instance->changeScene(Game::instance->mainMenuScene);
				destroyed = true;
				break;
			}
			else {
				updateHearts(spaceShip->getHpPoints(), hearts);
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