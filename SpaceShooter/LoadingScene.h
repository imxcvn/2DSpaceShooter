#pragma once 

class LoadingScene : public Scene {
private:
	sf::RectangleShape background;
	sf::Texture mainTexture;
	std::string input;
	sf::Text playerName;
	sf::Font font;
	sf::Text text;
	sf::Text errorText;
	sf::Color color{ 255, 255, 255 };
public:
	LoadingScene(float width, float height);
	void render(sf::RenderWindow& window) override;
	bool isCorrect(const std::string& input);
	const std::string& getPlayerName();
	bool handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
};