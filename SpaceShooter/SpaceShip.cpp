#include "Includes.h"

SpaceShip::SpaceShip(Game* game) {
	if (!shapeTexture.loadFromFile("Texture/player_spaceship.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	shape.setTexture(shapeTexture);
	sf::Vector2u textureSize = shapeTexture.getSize();
	sizeX = 50.f;
	sizeY = 50.f;
	float scaleX = sizeX / textureSize.x;
	float scaleY = sizeY / textureSize.y;
	shape.setScale(scaleX, scaleY);
	vx = 0.f;
	vy = 0.f;
	this->game = game;
}

void SpaceShip::update(float elapsed) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(Game::instance->gameWindow);
	px = mousePosition.x;

	/*float deltaX = vx * elapsed / 1000;
	float deltaY = vy * elapsed / 1000;
	px += deltaX;
	py += deltaY;
	if (py + sizeY >= game->screenSize.y && vy > 0) {

		vy = -vy;
	}
	else if (py <= 0 && vy < 0) {
		vy = -vy;
	}
	if (px + sizeX >= game->screenSize.x && vx > 0) {
		vx = -vx;
	}
	else if (px <= 0 && vx < 0) {
		vx = -vx;
	}*/
}

void SpaceShip::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}

void SpaceShip::setPosition(float x, float y) {
	px = x;
	py = y;
}