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
	canGetDestroyedByProjectile = false;
}
