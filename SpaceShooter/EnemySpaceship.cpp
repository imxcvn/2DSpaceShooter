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
	canGetDestroyedByProjectile = true;
}

void EnemySpaceship::update(float elapsed) {
	EnemyObject::update(elapsed);
	elapsedSum += elapsed;
	if (elapsedSum >= 1000) {
		elapsedSum -= 1000;
		EnemyProjectile* eProjectile = new EnemyProjectile{ Game::instance , px + 0.5f * sizeX, py + sizeY };
		eProjectile->setDamage(damage);
		Game::instance->playScene->addEnemyProjectile(eProjectile);
	}
}


