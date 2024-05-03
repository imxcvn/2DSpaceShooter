#pragma once

class Game {
public:
	static Game* instance;
	HighScoreScene* highScoreScene;
	PlayScene* playScene;
	MainMenuScene* mainMenuScene;
	Scene* currentScene;
	Scene* nextScene;
	sf::Vector2f screenSize;
	Game();
	void initialize();
	void update(float elapsed);
	void render(sf::RenderWindow& window);
	bool handleEvent(const sf::Event& e, sf::RenderWindow& window);
	void changeScene(Scene* newScene);
	~Game();
};