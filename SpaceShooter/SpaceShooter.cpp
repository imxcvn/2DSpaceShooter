#include "Includes.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(820, 940), "Space Odyssey", sf::Style::Default);
	window.setVerticalSyncEnabled(true);
	//window.setMouseCursorVisible(false);

	sf::Clock clock;

	Game game{window};
	game.screenSize = { 820, 940 };
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
		}
		sf::Time time = clock.restart();
		float elapsed = time.asSeconds() * 1000;
		game.update(elapsed);
		window.clear();
		game.render(window);
		window.display();
	}

	return 0;
}
