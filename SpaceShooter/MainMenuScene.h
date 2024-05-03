#pragma once

#define Max_main_menu 3
class MainMenuScene : public Scene {
private:
	int MainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[Max_main_menu];
	sf::Color inactiveColor{ sf::Color::White };
	sf::Color activeColor{ 208, 133, 242 };
	sf::RectangleShape background;
	sf::Texture mainTexture;
public:
	MainMenuScene(float width, float hight);
	void render(sf::RenderWindow& window) override;
	void moveUp();
	void moveDown();
	int MainMenuPressed();
	bool handleEvent(const sf::Event& e, sf::RenderWindow& window) override;
	~MainMenuScene();
};