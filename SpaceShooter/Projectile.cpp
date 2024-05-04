#include "Includes.h"

Projectile::Projectile(Game* game) {
	if (!shapeTexture.loadFromFile("Texture/player_projectile.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	shape.setTexture(shapeTexture);
	sf::Vector2u textureSize = shapeTexture.getSize();
	scaleX = 50.f / textureSize.x;
	scaleY = 50.f / textureSize.y;
	shape.setScale(scaleX, scaleY);
	this->game = game;
}

void Projectile::update(float elapsed) {
	float deltaX = vx * elapsed / 1000;
	float deltaY = vy * elapsed / 1000;
	px += deltaX;
	py += deltaY;
	if (py + scaleY >= game->screenSize.y && vy > 0) {

		vy = -vy;
	}
	else if (py - scaleY <= 0 && vy < 0) {
		vy = -vy;
	}
	if (px + scaleX >= game->screenSize.x && vx > 0) {
		vx = -vx;
	}
	else if (px - scaleX <= 0 && vx < 0) {
		vx = -vx;
	}
}

void Projectile::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}