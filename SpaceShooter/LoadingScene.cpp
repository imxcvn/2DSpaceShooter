#include "Includes.h"

LoadingScene::LoadingScene(float width, float hight) {
	if (!font.loadFromFile("Font/ARCADE.ttf")) {
		std::cout << "Nie ma czcionki." << std::endl;
	}

	text.setFont(font);
	text.setFillColor(color);
	text.setString("Enter your name");
	text.setCharacterSize(100);
	text.setPosition(140, 200);

	playerName.setFont(font);
	playerName.setFillColor(color);
	playerName.setString(input);
	playerName.setCharacterSize(80);
	playerName.setPosition(380, 350);

	errorText.setFont(font);
	errorText.setFillColor(color);
	errorText.setCharacterSize(70);
	errorText.setPosition(180, 400);

	background.setSize(sf::Vector2f(960, 720));
	mainTexture.loadFromFile("Texture/SpaceBackground3.png");
	background.setTexture(&mainTexture);
}

void LoadingScene::render(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(text);
	window.draw(playerName);
	window.draw(errorText);
}

const std::string& LoadingScene::getPlayerName() {
	return playerName.getString();
}

bool LoadingScene::isCorrect(const std::string& input) {
	std::regex pattern("^[A-Z][a-zA-Z]{0,12}");
	if (!input.empty()) {
		if (std::regex_match(input, pattern)) {
			return true;
		}
	}
	return false;
}

bool LoadingScene::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
	if (event.type == sf::Event::TextEntered) {
		errorText.setString("");
		if (event.text.unicode == 13) { //enter 
			if (isCorrect(input)) {
				Game::instance->setPlayerName(input);
				Game::instance->changeScene(Game::instance->mainMenuScene);
				return true;
			}
			else {
				errorText.setString("Invalid player name.\n Please try again.");
				input.clear();
				playerName.setString(input);
				return false;
			}
		}
		else if (event.text.unicode == 8) { //backspace
			if (!input.empty()) {
				input.pop_back();
				playerName.setString(input);
			}
		}
		else if (event.text.unicode < 128) { //reszta
			input += static_cast<char>(event.text.unicode);
			playerName.setString(input);
		}
	}

	else if (event.type == sf::Event::Closed) {
		window.close();
		return true;
	}

	return false;
}


/*
bool LoadingScene::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Return) {
			if (isCorrect(input)) {
				Game::instance->changeScene(Game::instance->mainMenuScene);
				return true;
			} else



		}
	}
	return false;
}
*/