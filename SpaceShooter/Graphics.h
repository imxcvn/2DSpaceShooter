#pragma once

class Graphics {
public:
	static Graphics* instance;
	sf::Texture asteroidTexture;
	sf::Texture smallAsteroidTexture;
	sf::Texture enemyProjectileTexture;
	sf::Texture enemySpaceshipTexture;
	sf::Texture enemySpaceshipTexture2;
	sf::Texture playerProjectileTexture;
	sf::Texture playerSpaceshipTexture;
	sf::Texture oneHeart;
	sf::Texture shotTexture;

	sf::Texture highScoreTexture;
	sf::Texture loadingScreenTexture;
	sf::Texture mainMenuTexture;
	sf::Texture bgTexture;
	sf::Texture starsTexture;
	sf::Texture stars20Texture;

	Graphics();
	void loadTextures();
	static void setTexture(sf::Sprite& shape, sf::Texture& texture, float sizeX, float sizeY);
	static void setBgTexture(sf::RectangleShape& shape, sf::Texture& texture);
};