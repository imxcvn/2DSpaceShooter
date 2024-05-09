#include "Includes.h"

Projectile::Projectile(Game* game) {
	if (!shapeTexture.loadFromFile("Texture/player_projectile2.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	
	px = game->getPositionX();
	py = game->getPositionY();
	
	shape.setTexture(shapeTexture);
	sf::Vector2u textureSize = shapeTexture.getSize();
	sizeX = 10.f;
	sizeY = 16.f;
	float scaleX = sizeX / textureSize.x;
	float scaleY = sizeY / textureSize.y;
	shape.setScale(scaleX, scaleY);
	shape.setOrigin(scaleX/2, scaleY/2);
	this->game = game;
}

void Projectile::update(float elapsed) {
	//float deltaX = vx * elapsed / 1000;
	float deltaY = vy * elapsed / 1000;
	//px += deltaX;
	py += deltaY;
	if (py + sizeY >= game->screenSize.y && vy > 0) {

		vy = -vy;
	}
	/*else if (py <= 0 && vy < 0) {
		vy = -vy;
	}
	if (px + sizeX/2 >= game->screenSize.x && vx > 0) {
		vx = -vx;
	}
	else if (px <= 0 && vx < 0) {
		vx = -vx;
	}*/
}

void Projectile::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}