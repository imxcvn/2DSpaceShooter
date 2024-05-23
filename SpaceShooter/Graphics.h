#pragma once

class Graphics {
public:
	static Graphics* instance;
	sf::Texture asteroidTexture;
	sf::Texture smallAsteroidTexture;
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

	sf::SoundBuffer endBuffer;
	sf::SoundBuffer enemyBuffer;
	sf::SoundBuffer playerBuffer;
	sf::SoundBuffer clickBuffer;
	sf::SoundBuffer enterBuffer;
	sf::SoundBuffer scoreBuffer;
	sf::SoundBuffer shootBuffer;
	sf::SoundBuffer scoreScreenBuffer;
	sf::SoundBuffer typingBuffer;
	sf::SoundBuffer correctBuffer;
	sf::SoundBuffer errorBuffer;
	sf::SoundBuffer musicBuffer;
	Graphics();
	void loadTextures();
	static void setTexture(sf::Sprite& shape, sf::Texture& texture, float sizeX, float sizeY);
	static void setBgTexture(sf::RectangleShape& shape, sf::Texture& texture);
};