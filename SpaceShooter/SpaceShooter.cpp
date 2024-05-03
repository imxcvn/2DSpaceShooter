#include "Includes.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(960, 720), "Main Menu", sf::Style::Default);
	//MainMenu mainMenu(window.getSize().x, window.getSize().y);
	
	window.setVerticalSyncEnabled(true);

	//tlo menu
	sf::Clock clock;


	/*MainMenuScene mainMenu(window.getSize().x, window.getSize().y);
	Scene* currentScene = &mainMenu;*/
	Game game;
	game.screenSize = { 960, 720 };
	game.initialize();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else {

				game.handleEvent(event, window);
			}

			/*if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Up) {
					mainMenu.moveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down) {
					mainMenu.moveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return) {
					sf::RenderWindow Play(sf::VideoMode(960, 720), "gameName");
					sf::RenderWindow HScore(sf::VideoMode(960, 720), "Highest Score");

					int x = mainMenu.MainMenuPressed();
					if (x == 0) {
						while (Play.isOpen()) {
							sf::Event e;
							while (Play.pollEvent(e)) {
								if (e.type == sf::Event::Closed) {
									Play.close();
								}
								if (e.type == sf::Event::KeyPressed) {
									if (e.key.code == sf::Keyboard::Escape) {
										Play.close();
									}
								}
							}
							HScore.close();
							Play.clear();
							Play.draw(backgroundP);
							Play.display();
						}
					}
					if (x == 1) {
						while (HScore.isOpen()) {
							sf::Event e;
							while (HScore.pollEvent(e)) {
								if (e.type == sf::Event::Closed) {
									HScore.close();
								}
								if (e.type == sf::Event::KeyPressed) {
									if (e.key.code == sf::Keyboard::Escape) {
										HScore.close();
									}
								}
							}
							Play.close();
							HScore.clear();
							HScore.draw(backgroundHS);
							HScore.display();
						}
					}
					if (x == 2) {
						window.close();
					}
					break;
				}
			}*/
		}
		sf::Time time = clock.restart();
		float elapsed = time.asSeconds() * 1000;
		game.update(elapsed);
		window.clear();
		//window.draw(background);
		game.render(window);

		window.display();
	}

	return 0;
}
