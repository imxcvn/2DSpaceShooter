#include "Includes.h"

HighScoreScene::HighScoreScene(float width, float height, LoadingScene* loadingScene) {
	if (!font.loadFromFile("Font/ARCADE.ttf")) {
		std::cout << "Nie ma czcionki." << std::endl;
	}

	text.setFont(font);
	text.setFillColor(color);
	text.setCharacterSize(90);
	text.setString("highest score:");
	
	name.setFont(font);
	name.setFillColor(color);
	name.setCharacterSize(90);

	highestScore.setFont(font);
	highestScore.setFillColor({ 157, 179, 245 });
	highestScore.setString(std::to_string(Score));
	highestScore.setCharacterSize(210);
	
	highestScore.setOutlineColor(sf::Color::White);
	highestScore.setOutlineThickness(3.5);

	background.setSize(sf::Vector2f(820, 940));
	mainTexture.loadFromFile("Texture/SpaceBackground2.png");
	background.setTexture(&mainTexture);

	backgroundStars.setSize(sf::Vector2f(820, 940));
	starTexture.loadFromFile("Texture/stars2.png");
	backgroundStars.setTexture(&starTexture);
}

void HighScoreScene::render(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(backgroundStars);
	window.draw(highestScore);
	window.draw(name);
	window.draw(text);
}

void HighScoreScene::shown() {
	name.setString(Game::instance->getPlayerName() + "'s");
	highestScore.setString(std::to_string(Game::instance->getScore()));
	float x = Game::instance->screenSize.x/2 - name.getLocalBounds().width/2;
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

