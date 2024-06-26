#include "Includes.h"

LoadingScene::LoadingScene(float width, float hight) {
	if (!font.loadFromFile("Font/ARCADE.ttf")) {
		std::cout << "Nie ma czcionki." << std::endl;
	}

	text.setFont(font);
	text.setFillColor({ 108, 171, 115 });
	text.setString("Enter your\n  name:");
	text.setCharacterSize(125);
	text.setPosition(150, 200);
	text.setOutlineColor(sf::Color::White);
	text.setOutlineThickness(2);

	playerName.setFont(font);
	playerName.setFillColor(color);
	playerName.setString(input);
	playerName.setCharacterSize(80);
	playerName.setOutlineColor(sf::Color::Black);
	playerName.setOutlineThickness(1.5);

	errorText.setFont(font);
	errorText.setFillColor(color);
	errorText.setCharacterSize(70);
	errorText.setPosition(130, 640);
	errorText.setOutlineColor(sf::Color::Black);
	errorText.setOutlineThickness(1.5);

	Graphics::setBgTexture(background, Graphics::instance->loadingScreenTexture);

	sound.setBuffer(Sound::instance->scoreScreenBuffer);

	clickSound.setBuffer(Sound::instance->typingBuffer);
	clickSound.setVolume(20.f);

	correctSound.setBuffer(Sound::instance->correctBuffer);
	correctSound.setVolume(30.f);

	errorSound.setBuffer(Sound::instance->errorBuffer);
	errorSound.setVolume(30.f);

	deleteSound.setBuffer(Sound::instance->deleteBuffer);
	deleteSound.setVolume(30.f);
}

void LoadingScene::render(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(text);
	window.draw(playerName);
	window.draw(errorText);
}

std::string LoadingScene::getPlayerName() {
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
		float x = Game::instance->screenSize.x / 2 - playerName.getLocalBounds().width / 2;
		playerName.setPosition(x, 510);
		errorText.setString("");
		if (event.text.unicode == 13) {
			if (isCorrect(input)) {
				correctSound.play();
				Game::instance->setPlayerName(input);
				Game::instance->changeScene(Game::instance->mainMenuScene);
				sound.play();
				return true;
			}
			else {
				errorSound.play();
				errorText.setString("Invalid player name.\n Please try again.");
				input.clear();
				playerName.setString(input);
				x = Game::instance->screenSize.x / 2 - playerName.getLocalBounds().width / 2;
				playerName.setPosition(x, 510);
				return false;
			}
		}
		else if (event.text.unicode == 8) {
			if (!input.empty()) {
				deleteSound.play();
				input.pop_back();
				playerName.setString(input);
				x = Game::instance->screenSize.x / 2 - playerName.getLocalBounds().width / 2;
				playerName.setPosition(x, 510);
			}
		}
		else if (event.text.unicode < 128 && event.text.unicode > 32) {
			clickSound.play();
			input += static_cast<char>(event.text.unicode);
			playerName.setString(input);
			x = Game::instance->screenSize.x / 2 - playerName.getLocalBounds().width / 2;
			playerName.setPosition(x, 510);
		} 
		else if (event.text.unicode == 27) {
			window.close();
			return true;
		}
	}
	else if (event.type == sf::Event::Closed) {
		window.close();
		return true;
	}
	return false;
}

