#pragma once

class HighScoreScene : public Scene {
private:
	sf::RectangleShape background;
	sf::Texture mainTexture;
	int Score = 1000;
	sf::Font font;
	sf::Text highestScore;
	sf::Color color{ 255, 255, 255 };
	sf::Text text;
public:
	HighScoreScene(float width, float height);
	void render(sf::RenderWindow& window) override;
	bool handleEvent(const sf::Event& event, sf::RenderWindow& window) override;

};