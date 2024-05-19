#pragma once

class Graphics {
public:
	static Graphics* instance;
	sf::Texture asteroidTexture;
	sf::Texture enemyProjectileTexture;
	sf::Texture enemySpaceshipTexture;
	sf::Texture playerProjectileTexture;
	sf::Texture playerSpaceshipTexture;
	sf::Texture oneHeart;
	sf::Texture twoHearts;
	sf::Texture threeHearts;

	sf::Texture highScoreTexture;
	sf::Texture loadingScreenTexture;
	sf::Texture playScreenTexture;
	sf::Texture mainMenuTexture;
	Graphics();
	void loadTextures();
	static void setTexture(sf::Sprite& shape, sf::Texture& texture, float sizeX, float sizeY);
	static void setBgTexture(sf::RectangleShape& shape, sf::Texture& texture);
};