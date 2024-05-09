#include "Includes.h"

SpaceShip::SpaceShip(Game* game) {
	if (!shapeTexture.loadFromFile("Texture/player_spaceship.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	shape.setTexture(shapeTexture);
	sf::Vector2u textureSize = shapeTexture.getSize();
	sizeX = 70.f;
	sizeY = 70.f;
	float scaleX = sizeX / textureSize.x;
	float scaleY = sizeY / textureSize.y;
	shape.setScale(scaleX, scaleY);
	px = game->screenSize.x / 2;   // ustawic pozycje poczatkowa 
	py = game->screenSize.y;
	/*vx = 0.f;
	vy = 0.f;*/
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

}

void SpaceShip::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}

void SpaceShip::setPosition(float x, float y) {
	px = x;
	py = y;
}