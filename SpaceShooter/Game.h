#pragma once

class Game {
public:
	static Game* instance;
	HighScoreScene* highScoreScene;
	PlayScene* playScene;
	MainMenuScene* mainMenuScene;
	LoadingScene* loadingScene;
	Scene* currentScene;
	Scene* nextScene;
	sf::Vector2f screenSize;
	std::string playerName;
	sf::RenderWindow& gameWindow;
	Game(sf::RenderWindow& window);
	void initialize();
	void update(float elapsed);
	void render(sf::RenderWindow& window);
	void setPlayerName(const std::string& name);
	const std::string& getPlayerName() const;
	bool handleEvent(const sf::Event& e, sf::RenderWindow& window);
	void changeScene(Scene* newScene);
	~Game();
};