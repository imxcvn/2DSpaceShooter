#include "Includes.h"

float EnemyObject::getPositionX() const {
	return px + sizeX / 2;
}

float EnemyObject::getPositionY() const {
	return py + sizeY;
}

bool EnemyObject::getCanBeDestroyedByProjectile() const {
	return canGetDestroyedByProjectile;
}

void EnemyObject::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}

void EnemyObject::update(float elapsed) {
	float deltaX = vx * elapsed / 1000;
	float deltaY = vy * elapsed / 1000;
	px += deltaX;
	py += deltaY;
	if (py >= Game::instance->screenSize.y) {
		destroyLater();
	}
}

sf::Rect<float> EnemyObject::getLocalBounds() const {
	return { 0, 0, sizeX, sizeY };
}