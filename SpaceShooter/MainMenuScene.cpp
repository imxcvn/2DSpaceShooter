#include "Includes.h"


MainMenuScene::MainMenuScene(float width, float hight) {
	if (!font.loadFromFile("Font/ARCADE.ttf")) {
		std::cout << "Nie ma czcionki." << std::endl;
	}

	mainMenu[0].setFont(font);
	mainMenu[0].setString("Space Odyssey");
	mainMenu[0].setCharacterSize(125);
	mainMenu[0].setPosition(65, 100);
	mainMenu[0].setFillColor({187, 161, 227});
	mainMenu[0].setOutlineColor({231,225,237});
	mainMenu[0].setOutlineThickness(4);

	mainMenu[1].setFont(font);
	mainMenu[1].setString("Play");
	mainMenu[1].setCharacterSize(90);
	mainMenu[1].setPosition(410, 270);
	mainMenu[1].setFillColor(activeColor);
	mainMenu[1].setOutlineColor(sf::Color::White);
	mainMenu[1].setOutlineThickness(3);

	mainMenu[2].setFont(font);
	mainMenu[2].setString("Highest Score");
	mainMenu[2].setCharacterSize(90);
	mainMenu[2].setPosition(230, 390);
	mainMenu[2].setOutlineColor(sf::Color::Black);
	mainMenu[2].setOutlineThickness(1.5);

	mainMenu[3].setFont(font);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(90);
	mainMenu[3].setPosition(410, 530);
	mainMenu[3].setOutlineColor(sf::Color::Black);
	mainMenu[3].setOutlineThickness(1.5);

	MainMenuSelected = 1;

	background.setSize(sf::Vector2f(960, 720));
	backgroundStars.setSize(sf::Vector2f(960, 720));
	backgroundStars2.setSize(sf::Vector2f(960, 720));

	mainTexture.loadFromFile("Texture/SpaceBackground.png");
	background.setTexture(&mainTexture);

	starTexture.loadFromFile("Texture/stars1.png");
	backgroundStars.setTexture(&starTexture);

	starTexture2.loadFromFile("Texture/stars3.png");
	backgroundStars2.setTexture(&starTexture2);
}
void MainMenuScene::render(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(backgroundStars);
	window.draw(backgroundStars2);
	for (int i = 0; i < max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
}
void MainMenuScene::moveUp() {
	if (MainMenuSelected - 1 >= 1) {

		mainMenu[MainMenuSelected].setFillColor(inactiveColor);
		mainMenu[MainMenuSelected].setOutlineColor(sf::Color::Black);
		mainMenu[MainMenuSelected].setOutlineThickness(1.5);
		MainMenuSelected--;
		if (MainMenuSelected == 0) {
			MainMenuSelected = 3;
		}
		mainMenu[MainMenuSelected].setFillColor(activeColor);
		mainMenu[MainMenuSelected].setOutlineColor(sf::Color::White);
		mainMenu[MainMenuSelected].setOutlineThickness(3);
	}
}
void MainMenuScene::moveDown() {
	if (MainMenuSelected + 1 <= max_main_menu) {
		if (MainMenuSelected >= 1) {
			mainMenu[MainMenuSelected].setFillColor(inactiveColor);
			mainMenu[MainMenuSelected].setOutlineColor(sf::Color::Black);
			mainMenu[MainMenuSelected].setOutlineThickness(1.5);
		}

		MainMenuSelected++;
		if (MainMenuSelected == 4) {
			MainMenuSelected = 1;
		}
		mainMenu[MainMenuSelected].setFillColor(activeColor);
		mainMenu[MainMenuSelected].setOutlineColor(sf::Color::White);
		mainMenu[MainMenuSelected].setOutlineThickness(3);
	}
}
int MainMenuScene::MainMenuPressed() {
	return MainMenuSelected;
}
bool MainMenuScene::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Up) {
			moveUp();
			return true;
		}
		if (event.key.code == sf::Keyboard::Down) {
			moveDown();
			return true;
		}
		if (event.key.code == sf::Keyboard::Return) {			

			int x = MainMenuPressed();
			if (x == 1) {
				Game::instance->changeScene(Game::instance->playScene);
			}
			if (x == 2) {
				Game::instance->changeScene(Game::instance->highScoreScene);
			}
			
			if (x == 3) {
				window.close();
			}
			
			
			return true;
		}
	}
	return false;
}
MainMenuScene::~MainMenuScene() {

}

