#include "Includes.h"

EnemyProjectile::EnemyProjectile(Game* game, float px, float py) {

	this->px = px;
	this->py = py;
	sizeX = 20.f;
	sizeY = 20.f;
	
	Graphics::setTexture(shape, Graphics::instance->enemyProjectileTexture, sizeX, sizeY);

	this->game = game;
}

sf::Rect<float> EnemyProjectile::getLocalBounds() const {
	return { 0, 0, 20.f, 20.f };
}

void EnemyProjectile::setDamage(int points) {
	damage = points;
}

int EnemyProjectile::getDamage() const {
	return damage;
}

void EnemyProjectile::update(float elapsed) {
	float deltaY = vy * elapsed / 1000;
	py += deltaY;
	if (py >= Game::instance->screenSize.y) {
		destroyLater();
	}
}

void EnemyProjectile::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}