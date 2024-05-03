#include "Includes.h"

GameObject::GameObject(Game* game) {
	if (!shapeTexture.loadFromFile("Texture/tile012.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	shape.setTexture(shapeTexture);
	sf::Vector2u textureSize = shapeTexture.getSize();
	scaleX = desiredWidth / textureSize.x;
	scaleY = desiredHeight / textureSize.y;
	shape.setScale(scaleX, scaleY);
	this->game = game;
}

void GameObject::update(float elapsed) {
	float deltaX = vx * elapsed / 1000;
	float deltaY = vy * elapsed / 1000;
	px += deltaX;
	py += deltaY;
	if (py - scaleY/2 >= game->screenSize.y && vy > 0) {

		vy = -vy;
	}
	else if (py - scaleY/2 <= 0 && vy < 0) {
		vy = -vy;
	}
	if (px - scaleX/2 >= game->screenSize.x && vx > 0) {
		vx = -vx;
	}
	else if (px - scaleX/2 <= 0 && vx < 0) {
		vx = -vx;
	}
}

void GameObject::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}