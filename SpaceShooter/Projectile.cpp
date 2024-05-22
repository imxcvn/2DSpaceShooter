#include "Includes.h"

Projectile::Projectile(Game* game) {
	
	sizeX = 15.f;
	sizeY = 24.f;
	px = game->getPositionX() - sizeX/2;
	py = game->getPositionY();
	
	Graphics::setTexture(shape, Graphics::instance->playerProjectileTexture, sizeX, sizeY);

	this->game = game;
}

sf::Rect<float> Projectile::getLocalBounds() const {
	return { 0, 0, 15.f, 24.f };
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