#include "Includes.h"

SpaceShip::SpaceShip(Game* game) {
	isShot = false;

	sizeX = 70.f;
	sizeY = 70.f;
	
	Graphics::setTexture(shape, Graphics::instance->playerSpaceshipTexture, sizeX, sizeY);

	px = game->screenSize.x / 2;  
	py = game->screenSize.y;
	hpPoints = 3;
	this->game = game;
}

void SpaceShip::update(float elapsed) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(Game::instance->gameWindow);
	px = mousePosition.x - sizeX / 2;
	py = mousePosition.y - sizeX / 2;
	Game::instance->setplayerPosition(px + sizeX/2, py);

	if (py <= 0) {
		py = 0;
	}
	if (py >= Game::instance->screenSize.y - sizeY) {
		py = Game::instance->screenSize.y - sizeY;
	}
	if (px <= 0) {
		px = 0;
		Game::instance->setplayerPosition(px + sizeX / 2, py);
	}
	if (px >= Game::instance->screenSize.x - sizeX) {
		px = Game::instance->screenSize.x - sizeX;
		Game::instance->setplayerPosition(px + sizeX / 2, py);
	}
    
	if (isShot == true) {

		blinkingTime += elapsed;
		if (blinkingTime >= 200) {
			
			blinkingTime -= 200;
			blinkCounter++;
			
			if (blinkCounter % 2 == 0) {
				shape.setTexture(Graphics::instance->shotTexture);
			}
			else {
				shape.setTexture(Graphics::instance->playerSpaceshipTexture);
			}
			if (blinkCounter >= 5) {
				isShot = false;
			}
		}
	}
}

void SpaceShip::startBlinking() {
	blinkCounter = 0;
	blinkingTime = 0;
	shape.setTexture(Graphics::instance->shotTexture);
	isShot = true;
}

sf::Rect<float> SpaceShip::getLocalBounds() const {
	return { 0, 0, sizeX, sizeY };
}

void SpaceShip::decreaseHealth(int damage) {
	if (isShot == false) {
		hpPoints -= damage;
	}
}

int SpaceShip::getHpPoints() const {
	return hpPoints;
}

void SpaceShip::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}

void SpaceShip::setPosition(float x, float y) {
	px = x;
	py = y;
}