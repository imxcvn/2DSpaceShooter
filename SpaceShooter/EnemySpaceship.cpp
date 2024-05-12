#include "Includes.h"

EnemySpaceship::EnemySpaceship(Game* game) {
	if (!shapeTexture.loadFromFile("Texture/enemy_spaceship1.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	shape.setTexture(shapeTexture);
	sf::Vector2u textureSize = shapeTexture.getSize();
	sizeX = 60.f;
	sizeY = 60.f;
	float scaleX = sizeX / textureSize.x;
	float scaleY = sizeY / textureSize.y;
	shape.setScale(scaleX, scaleY);
	px = float(rand()) / RAND_MAX * (game->screenSize.x - sizeX);    
	py = -sizeY;
	vy = 200.f;
	this->game = game;
}

sf::Rect<float> EnemySpaceship::getLocalBounds() const {
	return { 0, 0, sizeX, sizeY };
}

void EnemySpaceship::render(sf::RenderWindow& window) {
	shape.setPosition({ px,py });
	window.draw(shape);
}

void EnemySpaceship::update(float elapsed) {
	float deltaX = vx * elapsed / 1000;
	float deltaY = vy * elapsed / 1000;
	px += deltaX;
	py += deltaY;
	if (py >= Game::instance->screenSize.y) {
		destroyLater();
	}
}