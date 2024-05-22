#include "Includes.h"

SmallAsteroid::SmallAsteroid(Game* game) {
	sizeX = 30.f;
	sizeY = 30.f;
	Graphics::setTexture(shape, Graphics::instance->asteroidTexture, sizeX, sizeY);
	px = float(rand()) / RAND_MAX * (game->screenSize.x - sizeX);
	py = -sizeY;
	vy = 270.f;
	this->game = game;
	damage = 1;
}

sf::Rect<float> SmallAsteroid::getLocalBounds() const {
	return { 0, 0, sizeX, sizeY };
}

void SmallAsteroid::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}

int SmallAsteroid::getDamage() const {
	return damage;
}

void SmallAsteroid::update(float elapsed) {
	float deltaX = vx * elapsed / 1000;
	float deltaY = vy * elapsed / 1000;
	px += deltaX;
	py += deltaY;
	if (py >= Game::instance->screenSize.y) {
		destroyLater();
	}
}