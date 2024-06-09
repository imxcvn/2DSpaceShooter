#include "Includes.h"

Graphics* Graphics::instance = nullptr;

Graphics::Graphics() {
	instance = this;
}

void Graphics::loadTextures() {
	if (!std::filesystem::exists("Texture/asteroid.png")) {
		std::cout << "Brak tekstury dla asteroid." << std::endl;
	}
	asteroidTexture.loadFromFile("Texture/asteroid.png");

	if (!std::filesystem::exists("Texture/small_asteroid.png")) {
		std::cout << "Brak tekstury dla small_asteroid." << std::endl;
	}
	smallAsteroidTexture.loadFromFile("Texture/small_asteroid.png");
	
	if (!std::filesystem::exists("Texture/1heart.png")) {
		std::cout << "Brak tekstury dla oneHeart." << std::endl;
	}
	oneHeart.loadFromFile("Texture/1heart.png");

	if (!std::filesystem::exists("Texture/enemy_rojectile.png")) {
		std::cout << "Brak tekstury dla enemyProjectileTexture." << std::endl;
	}
	enemyProjectileTexture.loadFromFile("Texture/enemy_rojectile.png");
	
	if (!std::filesystem::exists("Texture/player_projectile.png")) {
		std::cout << "Brak tekstury dla playerProjectileTexture." << std::endl;
	}
	playerProjectileTexture.loadFromFile("Texture/player_projectile.png");

	if (!std::filesystem::exists("Texture/enemy_spaceship1.png")) {
		std::cout << "Brak tekstury dla enemySpaceshipTexture." << std::endl;
	}
	enemySpaceshipTexture.loadFromFile("Texture/enemy_spaceship1.png");

	if (!std::filesystem::exists("Texture/enemy_spaceship3.png")) {
		std::cout << "Brak tekstury dla enemySpaceshipTexture." << std::endl;
	}
	enemySpaceshipTexture2.loadFromFile("Texture/enemy_spaceship3.png");

	if (!std::filesystem::exists("Texture/player_spaceship.png")) {
		std::cout << "Brak tekstury dla playerSpaceshipTexture." << std::endl;
	}
	playerSpaceshipTexture.loadFromFile("Texture/player_spaceship.png");

	if (!std::filesystem::exists("Texture/player_spaceship1.png")) {
		std::cout << "Brak tekstury dla shotTexture." << std::endl;
	}
	shotTexture.loadFromFile("Texture/player_spaceship1.png");


	if (!std::filesystem::exists("Texture/SpaceBackground4.png")) {
		std::cout << "Brak tla dla ekranu high score." << std::endl;
	}
	highScoreTexture.loadFromFile("Texture/SpaceBackground4.png");

	if (!std::filesystem::exists("Texture/SpaceBackground3.png")) {
		std::cout << "Brak tla dla ekranu loading." << std::endl;
	}
	loadingScreenTexture.loadFromFile("Texture/SpaceBackground3.png");

	if (!std::filesystem::exists("Texture/SpaceBackground.png")) {
		std::cout << "Brak tla dla glownego menu." << std::endl;
	}
	mainMenuTexture.loadFromFile("Texture/SpaceBackground.png");

	if (!std::filesystem::exists("Texture/Space Background.png")) {
		std::cout << "Brak tla dla ekranu play." << std::endl;
	}
	bgTexture.loadFromFile("Texture/Space Background.png");

	if (!std::filesystem::exists("Texture/stars.png")) {
		std::cout << "Brak tla dla ekranu play." << std::endl;
	}
	starsTexture.loadFromFile("Texture/stars.png");

	if (!std::filesystem::exists("Texture/stars2.0.png")) {
		std::cout << "Brak tla dla ekranu play." << std::endl;
	}
	stars20Texture.loadFromFile("Texture/stars2.0.png");
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