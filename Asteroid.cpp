#include "Includes.h"

Asteroid::Asteroid(Game* game) {
	sizeX = 60.f;
	sizeY = 60.f;
	Graphics::setTexture(shape, Graphics::instance->asteroidTexture, sizeX, sizeY);
	px = float(rand()) / RAND_MAX * (game->screenSize.x - sizeX);
	py = -sizeY;
	vy = 250.f;
	this->game = game;
	damage = 2;
}

sf::Rect<float> Asteroid::getLocalBounds() const {
	return { 0, 0, sizeX, sizeY };
}

void Asteroid::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}

int Asteroid::getDamage() const {
	return damage;
}

void Asteroid::update(float elapsed) {
	float deltaX = vx * elapsed / 1000;
	float deltaY = vy * elapsed / 1000;
	px += deltaX;
	py += deltaY;
	if (py >= Game::instance->screenSize.y) {
		destroyLater();
	}
}