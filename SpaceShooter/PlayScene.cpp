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

	background.setSize(sf::Vector2f((float)Graphics::instance->bgTexture.getSize().x, (float)Graphics::instance->bgTexture.getSize().y));
	background.setTexture(&Graphics::instance->bgTexture);

	stars.setSize(sf::Vector2f((float)Graphics::instance->starsTexture.getSize().x, (float)Graphics::instance->starsTexture.getSize().y));
	stars.setTexture(&Graphics::instance->starsTexture);

	stars20a.setSize(sf::Vector2f((float)Graphics::instance->stars20Texture.getSize().x, (float)Graphics::instance->stars20Texture.getSize().y));
	stars20a.setTexture(&Graphics::instance->stars20Texture);
	stars20a.setPosition(0, 0);

	stars20b.setSize(sf::Vector2f((float)Graphics::instance->stars20Texture.getSize().x, (float)Graphics::instance->stars20Texture.getSize().y));
	stars20b.setTexture(&Graphics::instance->stars20Texture);
	stars20b.setPosition(0, -stars20b.getSize().y);

	Graphics::instance->setTexture(heart1, Graphics::instance->oneHeart, 50.f, 50.f);
	Graphics::instance->setTexture(heart2, Graphics::instance->oneHeart, 50.f, 50.f);
	Graphics::instance->setTexture(heart3, Graphics::instance->oneHeart, 50.f, 50.f);

	heart1.setPosition(650, 15);
	heart2.setPosition(700, 15);
	heart3.setPosition(750, 15);

	endSound.setBuffer(Sound::instance->endBuffer);

	enemySound.setBuffer(Sound::instance->enemyBuffer);
	enemySound.setVolume(60.f);

	playerSound.setBuffer(Sound::instance->playerBuffer);
	playerSound.setVolume(30.f);

	scoreSound.setBuffer(Sound::instance->scoreBuffer);

	shootSound.setBuffer(Sound::instance->shootBuffer);
	shootSound.setVolume(50.f);

	music.setBuffer(Sound::instance->musicBuffer);
	music.setVolume(20.f);
	music.setLoop(true);

	stars20ScrollSpeed = 0.1f;
}

void PlayScene::render(sf::RenderWindow& window) {
	float shipMinX = 0;
	float shipMaxX = Game::instance->screenSize.x - spaceShip->sizeX;
	float normalizedShipX = (spaceShip->getPositionX() - shipMinX) / (shipMaxX - shipMinX);

	float backgroundViewMinX = 0;
	float backgroundViewMaxX = Graphics::instance->bgTexture.getSize().x - Game::instance->screenSize.x;
	float backgroundX = backgroundViewMinX + normalizedShipX * (backgroundViewMaxX - backgroundViewMinX);

	float starsViewMinX = 0;
	float starsViewMaxX = Graphics::instance->starsTexture.getSize().x - Game::instance->screenSize.x;
	float starsX = starsViewMinX + normalizedShipX * (starsViewMaxX - starsViewMinX);

	/*float stars20ViewMinX = 0;
	float stars20ViewMaxX = Graphics::instance->stars20Texture.getSize().x - Game::instance->screenSize.x;
	float stars20X = stars20ViewMinX + normalizedShipX * (stars20ViewMaxX - stars20ViewMinX);*/

	background.setPosition(-backgroundX, background.getPosition().y);
	stars.setPosition(-starsX, stars.getPosition().y);
	//stars20.setPosition(-stars20X, stars20.getPosition().y);
	window.draw(background);
	window.draw(stars);
	window.draw(stars20a);
	window.draw(stars20b);

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
	window.draw(playerScore);
	window.draw(heart3);

	if (spaceShip->getHpPoints() >= 2) {
		window.draw(heart2);
		if (spaceShip->getHpPoints() == 3) {
			window.draw(heart1);
		}
	}
}

bool PlayScene::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			music.stop();
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
		enemies.push_back(asteroid);
		SmallAsteroid* sAsteroid = new SmallAsteroid{ Game::instance };
		enemies.push_back(sAsteroid);
		EnemySpaceship* spaceship = new EnemySpaceship{ Game::instance };
		enemies.push_back(spaceship);
		Game::instance->setEnemyPosition(spaceship->getPositionX(), spaceship->getPositionY());
		enemySpawnClock.restart();
	}
	if (secondEnemySpawnClock.getElapsedTime().asSeconds() >= 3.0f) {
		EnemySpaceship2* spaceship2 = new EnemySpaceship2{ Game::instance };
		enemies.push_back(spaceship2);
		Game::instance->setEnemyPosition(spaceship2->getPositionX(), spaceship2->getPositionY());
		secondEnemySpawnClock.restart();
	}
	return false;
}

void PlayScene::addEnemyProjectile(EnemyProjectile* projectile) {
	projectiles.push_back(projectile);
	enemySound.play();
}

void PlayScene::setScore(int score) {
	this->score = score;
	playerScore.setString(std::to_string(this->score));
}

void PlayScene::addScore(int score) {
	setScore(this->score + score);
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
	music.play();
}

void PlayScene::gameOver() {
	music.stop();
	endSound.play();
	Game::instance->changeScene(Game::instance->mainMenuScene);
	if (score >= Game::instance->getScore()) {

		Game::instance->setScore(score);
	}
}

void PlayScene::update(float elapsed) {

	float stars20aY = stars20a.getPosition().y + stars20ScrollSpeed * elapsed;
	float stars20bY = stars20b.getPosition().y + stars20ScrollSpeed * elapsed;

	if (stars20aY > Game::instance->screenSize.y) {
		stars20aY -= 2 * stars20a.getSize().y;
	}
	if (stars20bY > Game::instance->screenSize.y) {
		stars20bY -= 2 * stars20b.getSize().y;
	}

	stars20a.setPosition(stars20a.getPosition().x, stars20aY);
	stars20b.setPosition(stars20b.getPosition().x, stars20bY);

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
			if (enemies[j]->getCanBeDestroyedByProjectile()) {
				sf::Rect<float> eBounds = enemies[j]->getGlobalBounds();
				if (pBounds.intersects(eBounds)) {
					addScore(enemies[j]->getScore());
					scoreSound.play();
					delete enemies[j];
					delete objects[i];
					objects.erase(objects.begin() + i);
					enemies.erase(enemies.begin() + j);
					destroyed = true;
					break;
				}
			}
		}
		if (destroyed == false) {
			i++;
		}
	}

	for (int i = 0; i < enemies.size(); ) {
		sf::Rect<float> eBounds = enemies[i]->getGlobalBounds();
		bool destroyed = false;
		sf::Rect<float> sBounds = spaceShip->getGlobalBounds();
		if (eBounds.intersects(sBounds)) {
			shootSound.play();
			spaceShip->decreaseHealth(enemies[i]->getDamage());
			spaceShip->startBlinking();
			delete enemies[i];
			enemies.erase(enemies.begin() + i);
			destroyed = true;
			if (spaceShip->getHpPoints() <= 0) {
				gameOver();
				break;
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
			shootSound.play();
			spaceShip->decreaseHealth(projectiles[i]->getDamage());
			spaceShip->startBlinking();
			delete projectiles[i];
			projectiles.erase(projectiles.begin() + i);
			destroyed = true;
			if (spaceShip->getHpPoints() <= 0) {
				gameOver();
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