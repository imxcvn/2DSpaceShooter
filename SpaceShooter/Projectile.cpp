#include "Includes.h"

Projectile::Projectile(Game* game) {
	
	px = game->getPositionX();
	py = game->getPositionY();
	
	sizeX = 10.f;
	sizeY = 16.f;
	
	Graphics::setTexture(shape, Graphics::instance->playerProjectileTexture, sizeX, sizeY);

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