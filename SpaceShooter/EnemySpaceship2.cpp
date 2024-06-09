#include "Includes.h"

EnemySpaceship2::EnemySpaceship2(Game* game) {
	elapsedSum = 0;

	sizeX = 60.f;
	sizeY = 60.f;
	Graphics::setTexture(shape, Graphics::instance->enemySpaceshipTexture2, sizeX, sizeY);

	px = float(rand()) / RAND_MAX * (game->screenSize.x - sizeX);
	py = -sizeY;
	vy = 220.f;
	this->game = game;
	score = 150;
	damage = 2;
	canGetDestroyedByProjectile = true;
}

void EnemySpaceship2::update(float elapsed) {
	EnemyObject::update(elapsed);
	elapsedSum += elapsed;
	if (elapsedSum >= 1000) {
		elapsedSum -= 1000;
		EnemyProjectile* eProjectile = new EnemyProjectile{ Game::instance , px + 0.5f * sizeX, py + sizeY };
		eProjectile->setDamage(damage);
		Game::instance->playScene->addEnemyProjectile(eProjectile);
	}
}


