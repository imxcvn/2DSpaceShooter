#include "Includes.h"

EnemySpaceship::EnemySpaceship(Game* game) {
	elapsedSum = 0;

	sizeX = 60.f;
	sizeY = 60.f;
	Graphics::setTexture(shape, Graphics::instance->enemySpaceshipTexture, sizeX, sizeY);

	px = float(rand()) / RAND_MAX * (game->screenSize.x - sizeX);    
	py = -sizeY;
	vy = 200.f;
	this->game = game;
	score = 100;
	damage = 1;
}

sf::Rect<float> EnemySpaceship::getLocalBounds() const {
	return { 0, 0, sizeX, sizeY };
}

float EnemySpaceship::getPositionX() const {
	return px + sizeX/2;
}

float EnemySpaceship::getPositionY() const {
	return py + sizeY;
}

int EnemySpaceship::getScore() const {
	return score;
}

void EnemySpaceship::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}

int EnemySpaceship::getDamage() const {
	return damage;
}

void EnemySpaceship::update(float elapsed) {
	float deltaX = vx * elapsed / 1000;
	float deltaY = vy * elapsed / 1000;
	px += deltaX;
	py += deltaY;
	if (py >= Game::instance->screenSize.y) {
		destroyLater();
	}
	elapsedSum += elapsed;
	if (elapsedSum >= 1000) {
		elapsedSum -= 1000;
		EnemyProjectile* eProjectile = new EnemyProjectile{ Game::instance , px + 0.5f * sizeX, py + sizeY};
		eProjectile->setDamage(damage);
		Game::instance->playScene->addEnemyProjectile(eProjectile);
	}
}