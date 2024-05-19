#include "Includes.h"

Graphics* Graphics::instance = nullptr;

Graphics::Graphics() {
	instance = this;
}

void Graphics::loadTextures() {
	if (!asteroidTexture.loadFromFile("Texture/asteroid.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	if (!oneHeart.loadFromFile("Texture/1heart.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	if (!twoHearts.loadFromFile("Texture/2hearts.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	if (!threeHearts.loadFromFile("Texture/3hearts.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	if (!enemyProjectileTexture.loadFromFile("Texture/tile026.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	if (!playerProjectileTexture.loadFromFile("Texture/player_projectile.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	if (!enemySpaceshipTexture.loadFromFile("Texture/enemy_spaceship1.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	if (!playerSpaceshipTexture.loadFromFile("Texture/player_spaceship.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
}

void Graphics::setTexture(sf::Sprite& shape, sf::Texture& texture, float sizeX, float sizeY) {
	shape.setTexture(texture);
	sf::Vector2u textureSize = texture.getSize();
	float scaleX = sizeX / textureSize.x;
	float scaleY = sizeY / textureSize.y;
	shape.setScale(scaleX, scaleY);
}

void Graphics::setBgTexture(sf::RectangleShape& shape, sf::Texture& texture) {
	shape.setSize(sf::Vector2f(820, 940));
	shape.setTexture(&texture);
}