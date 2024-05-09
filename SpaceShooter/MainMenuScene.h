#pragma once

#define max_main_menu 4
class MainMenuScene : public Scene {
private:
	int MainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[max_main_menu];
	sf::Color inactiveColor{ sf::Color::White };
	sf::Color activeColor{ 150, 121, 199 };
	sf::RectangleShape background;
	sf::RectangleShape backgroundStars;
	sf::RectangleShape backgroundStars2;
	sf::Texture mainTexture;
	sf::Texture starTexture;
	sf::Texture starTexture2;
public:
	MainMenuScene(float width, float hight);
	void render(sf::RenderWindow& window) override;
	void moveUp();
	void moveDown();
	int MainMenuPressed();
	bool handleEvent(const sf::Event& e, sf::RenderWindow& window) override;
	~MainMenuScene();
};