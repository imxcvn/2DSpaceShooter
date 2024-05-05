#include "Includes.h"


MainMenuScene::MainMenuScene(float width, float hight) {
	if (!font.loadFromFile("Font/ARCADE.ttf")) {
		std::cout << "Nie ma czcionki." << std::endl;
	}

	mainMenu[0].setFont(font);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(90);
	mainMenu[0].setPosition(410, 240);
	mainMenu[0].setFillColor(activeColor);

	mainMenu[1].setFont(font);
	mainMenu[1].setString("Highest Score");
	mainMenu[1].setCharacterSize(90);
	mainMenu[1].setPosition(250, 360);

	mainMenu[2].setFont(font);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(90);
	mainMenu[2].setPosition(410, 500);

	MainMenuSelected = 0;

	background.setSize(sf::Vector2f(960, 720));

	mainTexture.loadFromFile("Texture/SpaceBackground.png");
	background.setTexture(&mainTexture);
}
void MainMenuScene::render(sf::RenderWindow& window) {
	window.draw(background);
	for (int i = 0; i < Max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
}
void MainMenuScene::moveUp() {
	if (MainMenuSelected - 1 >= 0) {

		mainMenu[MainMenuSelected].setFillColor(inactiveColor);
		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(activeColor);
	}
}
void MainMenuScene::moveDown() {
	if (MainMenuSelected + 1 <= Max_main_menu) {
		if (MainMenuSelected >= 0) {
			mainMenu[MainMenuSelected].setFillColor(inactiveColor);
		}

		MainMenuSelected++;
		if (MainMenuSelected == 3) {
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(activeColor);
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
			if (x == 0) {
				Game::instance->changeScene(Game::instance->playScene);
			}
			if (x == 1) {
				Game::instance->changeScene(Game::instance->highScoreScene);
			}
			
			if (x == 2) {
				window.close();
			}
			
			
			return true;
		}
	}
	return false;
}
MainMenuScene::~MainMenuScene() {

}

