//#pragma once
//#include "Includes.h"
//
//#define Max_main_menu 3
//class MainMenu {
//private:
//	int MainMenuSelected;
//	sf::Font font;
//	sf::Text mainMenu[Max_main_menu];
//	sf::Color inactiveColor{sf::Color::White};
//	sf::Color activeColor{208, 133, 242};
//public:
//	MainMenu(float width, float hight) {
//		if (!font.loadFromFile("Font/slkscr.ttf")) {
//			std::cout << "Nie ma czcionki." << std::endl;
//		}
//
//		mainMenu[0].setFont(font);
//		mainMenu[0].setString("Play");
//		mainMenu[0].setCharacterSize(70);
//		mainMenu[0].setPosition(220, 200);
//
//		mainMenu[1].setFont(font);
//		mainMenu[1].setString("Highest Score");
//		mainMenu[1].setCharacterSize(70);
//		mainMenu[1].setPosition(220, 300);
//
//		mainMenu[2].setFont(font);
//		mainMenu[2].setString("Exit");
//		mainMenu[2].setCharacterSize(70);
//		mainMenu[2].setPosition(220, 400);
//
//		MainMenuSelected = -1;
//	}
//	void draw(sf::RenderWindow& window) {
//		for (int i = 0; i < Max_main_menu; i++) {
//			window.draw(mainMenu[i]);
//		}
//	}
//	void moveUp() {
//		if (MainMenuSelected - 1 >= 0) {
//
//			mainMenu[MainMenuSelected].setFillColor(inactiveColor);
//			MainMenuSelected--;
//			if (MainMenuSelected == -1) {
//				MainMenuSelected = 2;
//			}
//			mainMenu[MainMenuSelected].setFillColor(activeColor);
//		}
//	}
//	void moveDown() {
//		if (MainMenuSelected + 1 <= Max_main_menu) {
//			if (MainMenuSelected >= 0) {
//				mainMenu[MainMenuSelected].setFillColor(inactiveColor);
//			}
//			
//			MainMenuSelected++;
//			if (MainMenuSelected == 3) {
//				MainMenuSelected = 0;
//			}
//			mainMenu[MainMenuSelected].setFillColor(activeColor);
//		}
//	}
//	int MainMenuPressed() {
//		return MainMenuSelected;
//	}
//	~MainMenu() {
//
//	}
//};