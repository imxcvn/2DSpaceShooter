#include "Includes.h"

Graphics* Graphics::instance = nullptr;

Graphics::Graphics() {
	instance = this;
}

void Graphics::loadTextures() {
	if (!asteroidTexture.loadFromFile("Texture/asteroid.png")) {
		std::cout << "Nie ma zdj." << std::endl;
	}
	if (!smallAsteroidTexture.loadFromFile("Texture/small_asteroid.png")) {
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


	if (!std::filesystem::exists("Texture/SpaceBackground4.png")) {
		std::cout << "Brak t?a dla ekranu high score." << std::endl;
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

	if (!std::filesystem::exists("Texture/SpaceBackground2.png")) {
		std::cout << "Brak tla dla ekranu play." << std::endl;
	}
	playScreenTexture.loadFromFile("Texture/SpaceBackground2.png");


	if (!endBuffer.loadFromFile("Sound/mixkit-arcade-fast-game-over-233.wav")) {
		std::cout << "Nie ma dzwieku dla konca gry." << std::endl;
	}
	if (!enemyBuffer.loadFromFile("Sound/d0e4-676a-484b-b3f5-817d482dbdef.wav")) {
		std::cout << "Nie ma dzwieku dla przeciwnika." << std::endl;
	}
	if (!playerBuffer.loadFromFile("Sound/mixkit-game-whip-shot-1512.wav")) {
		std::cout << "Nie ma dzwieku dla gracza." << std::endl;
	}
	if (!clickBuffer.loadFromFile("Sound/mixkit-space-coin-win-notification-271.wav")) {
		std::cout << "Nie ma dzwieku dla menu." << std::endl;
	}
	if (!enterBuffer.loadFromFile("Sound/mixkit-negative-game-notification-249.wav")) {
		std::cout << "Nie ma dzwieku dla enter." << std::endl;
	}
	if (!scoreBuffer.loadFromFile("Sound/affc-40a7-4b4c-8289-6c0790ff4436.wav")) {
		std::cout << "Nie ma dzwieku dla score." << std::endl;
	}
	if (!shootBuffer.loadFromFile("Sound/GUNPis_Pistol Fire Longer Tail_05.wav")) {
		std::cout << "Nie ma dzwieku dla shoot." << std::endl;
	}
	if (!scoreScreenBuffer.loadFromFile("Sound/Omnious 4 cut.wav")) {
		std::cout << "Nie ma dzwieku dla score screen." << std::endl;
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