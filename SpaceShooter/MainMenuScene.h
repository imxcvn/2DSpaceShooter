#pragma once

#define max_main_menu 4
class MainMenuScene : public Scene {
private:
	int MainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[max_main_menu];
	sf::Color inactiveColor{ 239, 230, 250 };
	sf::Color activeColor{ 144, 114, 181 };
	sf::RectangleShape background;
	sf::Sound sound1;
	sf::Sound sound2;
public:
	MainMenuScene(float width, float hight);
	void render(sf::RenderWindow& window) override;
	void moveUp();
	void moveDown();
	int MainMenuPressed();
	bool handleEvent(const sf::Event& e, sf::RenderWindow& window) override;
	~MainMenuScene();
};