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

sf::Rect<float> Projectile::getLocalBounds() const {
	return { 0, 0, 10.f, 16.f };
}

void Projectile::update(float elapsed) {
	float deltaY = vy * elapsed / 1000;
	py += deltaY;
	if (py <= 0 - sizeY) {
		destroyLater();
	}
}

void Projectile::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}