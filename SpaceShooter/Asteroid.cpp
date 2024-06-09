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
	canGetDestroyedByProjectile = false;
}
