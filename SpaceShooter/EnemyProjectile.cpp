#include "Includes.h"

EnemyProjectile::EnemyProjectile(Game* game) {
	if (!shapeTexture.loadFromFile("Texture/tile026.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}

	px = game->getEnemyPositionX();
	py = game->getEnemyPositionY();

	shape.setTexture(shapeTexture);
	sf::Vector2u textureSize = shapeTexture.getSize();
	sizeX = 20.f;
	sizeY = 20.f;
	float scaleX = sizeX / textureSize.x;
	float scaleY = sizeY / textureSize.y;
	shape.setScale(scaleX, scaleY);
	shape.setOrigin(scaleX / 2, scaleY / 2);
	this->game = game;
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