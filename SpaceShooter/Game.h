#pragma once

class Game {
public:
	static Game* instance;
	Graphics graphics;
	Sound sound;
	HighScoreScene* highScoreScene = nullptr;
	PlayScene* playScene = nullptr;
	MainMenuScene* mainMenuScene = nullptr;
	LoadingScene* loadingScene = nullptr;
	Scene* currentScene = nullptr;
	Scene* nextScene = nullptr;
	sf::Vector2f screenSize;
	std::string playerName;
	float playerPositionX = 0;
	float playerPositionY = 0;
	float enemyPositionX = 0;
	float enemyPositionY = 0;
	int playerScore = 0;
	sf::RenderWindow& gameWindow;
	Game(sf::RenderWindow& window);
	void initialize();
	void update(float elapsed);
	void render(sf::RenderWindow& window);
	void setPlayerName(const std::string& name);
	void setScore(int score);
	int getScore() const;
	const std::string& getPlayerName() const;
	void setplayerPosition(float px, float py);
	float getPositionX() const;
	float getPositionY() const;
	void setEnemyPosition(float px, float py);
	float getEnemyPositionX() const;
	float getEnemyPositionY() const;
	bool handleEvent(const sf::Event& e, sf::RenderWindow& window);
	void changeScene(Scene* newScene);
	~Game();
};