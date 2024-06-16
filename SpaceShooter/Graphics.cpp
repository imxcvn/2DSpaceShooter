#include "Includes.h"

Graphics* Graphics::instance = nullptr;

Graphics::Graphics() {
	instance = this;
}

void Graphics::loadTextures() {
	if (!std::filesystem::exists("Texture/asteroid.png")) {
		throw std::runtime_error("Brak tekstury dla asteroid.");
	}
	asteroidTexture.loadFromFile("Texture/asteroid.png");

	if (!std::filesystem::exists("Texture/small_asteroid.png")) {
		throw std::runtime_error("Brak tekstury dla small_asteroid.");
	}
	smallAsteroidTexture.loadFromFile("Texture/small_asteroid.png");
	
	if (!std::filesystem::exists("Texture/1heart.png")) {
		throw std::runtime_error("Brak tekstury dla oneHeart.");
	}
	oneHeart.loadFromFile("Texture/1heart.png");

	if (!std::filesystem::exists("Texture/enemy_rojectile.png")) {
		throw std::runtime_error("Brak tekstury dla enemyProjectileTexture.");
	}
	enemyProjectileTexture.loadFromFile("Texture/enemy_rojectile.png");
	
	if (!std::filesystem::exists("Texture/player_projectile.png")) {
		throw std::runtime_error("Brak tekstury dla playerProjectileTexture.");
	}
	playerProjectileTexture.loadFromFile("Texture/player_projectile.png");

	if (!std::filesystem::exists("Texture/enemy_spaceship1.png")) {
		throw std::runtime_error("Brak tekstury dla enemySpaceshipTexture.");
	}
	enemySpaceshipTexture.loadFromFile("Texture/enemy_spaceship1.png");

	if (!std::filesystem::exists("Texture/enemy_spaceship3.png")) {
		throw std::runtime_error("Brak tekstury dla enemySpaceshipTexture.");
	}
	enemySpaceshipTexture2.loadFromFile("Texture/enemy_spaceship3.png");

	if (!std::filesystem::exists("Texture/player_spaceship.png")) {
		throw std::runtime_error("Brak tekstury dla playerSpaceshipTexture.");
	}
	playerSpaceshipTexture.loadFromFile("Texture/player_spaceship.png");

	if (!std::filesystem::exists("Texture/player_spaceship1.png")) {
		throw std::runtime_error("Brak tekstury dla shotTexture.");
	}
	shotTexture.loadFromFile("Texture/player_spaceship1.png");


	if (!std::filesystem::exists("Texture/SpaceBackground4.png")) {
		throw std::runtime_error("Brak tla dla ekranu high score.");
	}
	highScoreTexture.loadFromFile("Texture/SpaceBackground4.png");

	if (!std::filesystem::exists("Texture/SpaceBackground3.png")) {
		throw std::runtime_error("Brak tla dla ekranu loading.");
	}
	loadingScreenTexture.loadFromFile("Texture/SpaceBackground3.png");

	if (!std::filesystem::exists("Texture/SpaceBackground.png")) {
		throw std::runtime_error("Brak tla dla glownego menu.");
	}
	mainMenuTexture.loadFromFile("Texture/SpaceBackground.png");

	if (!std::filesystem::exists("Texture/Space Background.png")) {
		throw std::runtime_error("Brak tla dla ekranu play.");
	}
	bgTexture.loadFromFile("Texture/Space Background.png");

	if (!std::filesystem::exists("Texture/stars.png")) {
		throw std::runtime_error("Brak tla dla ekranu play(stars).");
	}
	starsTexture.loadFromFile("Texture/stars.png");

	if (!std::filesystem::exists("Texture/stars2.0.png")) {
		throw std::runtime_error("Brak tla dla ekranu play(stars2.0).");
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