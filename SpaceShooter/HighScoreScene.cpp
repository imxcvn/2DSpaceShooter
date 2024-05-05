#include "Includes.h"

HighScoreScene::HighScoreScene(float width, float height, LoadingScene* loadingScene) {
	if (!font.loadFromFile("Font/ARCADE.ttf")) {
		std::cout << "Nie ma czcionki." << std::endl;
	}
	//playerName = loadingScene->getPlayerName();
	text.setFont(font);
	text.setFillColor(color);
	text.setCharacterSize(90);
	

	highestScore.setFont(font);
	highestScore.setFillColor(color);
	highestScore.setString(std::to_string(Score));
	highestScore.setCharacterSize(190);
	highestScore.setPosition(320, 350);

	background.setSize(sf::Vector2f(960, 720));
	mainTexture.loadFromFile("Texture/SpaceBackground2.png");
	background.setTexture(&mainTexture);
}

void HighScoreScene::render(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(highestScore);
	window.draw(text);
}

void HighScoreScene::shown() {
	text.setString(Game::instance->getPlayerName() + "'s highest score:");
	float x = Game::instance->screenSize.x/2 - text.getLocalBounds().width/2;
	text.setPosition(x, 200);
}


bool HighScoreScene::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			Game::instance->changeScene(Game::instance->mainMenuScene);
			return true;
		}
	}
	return false;
}

