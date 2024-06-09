#include "Includes.h"

HighScoreScene::HighScoreScene(float width, float height, LoadingScene* loadingScene) {
	if (!font.loadFromFile("Font/ARCADE.ttf")) {
		std::cout << "Nie ma czcionki." << std::endl;
	}

	text.setFont(font);
	text.setFillColor(color);
	text.setCharacterSize(90);
	text.setString("highest score:");
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(1.5);

	name.setFont(font);
	name.setFillColor(color);
	name.setCharacterSize(90);
	name.setOutlineColor(sf::Color::Black);
	name.setOutlineThickness(1.5);

	highestScore.setFont(font);
	highestScore.setFillColor({ 212, 102, 193 });
	highestScore.setString(std::to_string(Score));
	highestScore.setCharacterSize(210);
	highestScore.setOutlineColor(color);
	highestScore.setOutlineThickness(3.5);

	Graphics::setBgTexture(background, Graphics::instance->highScoreTexture);
}

void HighScoreScene::render(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(highestScore);
	window.draw(name);
	window.draw(text);
}

void HighScoreScene::shown() {
	name.setString(Game::instance->getPlayerName() + "'s");
	highestScore.setString(std::to_string(Game::instance->getScore()));
	float x = Game::instance->screenSize.x / 2 - name.getLocalBounds().width / 2;
	name.setPosition(x, 250);
	x = Game::instance->screenSize.x / 2 - text.getLocalBounds().width / 2;
	text.setPosition(x, 350);
	x = Game::instance->screenSize.x / 2 - highestScore.getLocalBounds().width / 2;
	highestScore.setPosition(x, 480);
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
