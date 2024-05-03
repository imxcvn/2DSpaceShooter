#include "Includes.h"

HighScoreScene::HighScoreScene(float width, float height) {
	if (!font.loadFromFile("Font/slkscr.ttf")) {
		std::cout << "Nie ma czcionki." << std::endl;
	}

	text.setFont(font);
	text.setFillColor(color);
	text.setString("Your highest score:");
	text.setCharacterSize(70);
	text.setPosition(50, 200);

	highestScore.setFont(font);
	highestScore.setFillColor(color);
	highestScore.setString(std::to_string(Score));
	highestScore.setCharacterSize(150);
	highestScore.setPosition(250, 350);

	background.setSize(sf::Vector2f(4600, 2600));
	mainTexture.loadFromFile("Texture/SpaceBackground2.png");
	background.setTexture(&mainTexture);
}

void HighScoreScene::render(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(highestScore);
	window.draw(text);
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

