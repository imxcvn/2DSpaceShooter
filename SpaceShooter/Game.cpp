#include "Includes.h"

Game* Game::instance = nullptr;

Game::Game(sf::RenderWindow& window)
:
	gameWindow{window}
{
	instance = this;
}

void Game::initialize() {
	graphics.loadTextures();
	loadingScene = new LoadingScene{ 820, 940 };
	mainMenuScene = new MainMenuScene{ 820, 940 };
	highScoreScene = new HighScoreScene{ 820, 940, loadingScene };
	playScene = new PlayScene{ 820, 940 };
	currentScene = loadingScene;
	nextScene = nullptr;
}
void Game::update(float elapsed) {
	currentScene->update(elapsed);
	if (nextScene != nullptr) {
		currentScene = nextScene;
		nextScene = nullptr;
		currentScene->shown();
	}
}
void Game::render(sf::RenderWindow& window) {
	currentScene->render(window);
}
bool Game::handleEvent(const sf::Event& e, sf::RenderWindow& window) {
	return currentScene->handleEvent(e, window);
}

void Game::setPlayerName(const std::string& name) {
	playerName = name;
}

void Game::setScore(int score) {
	playerScore = score;
}

int Game::getScore() const {
	return playerScore;
}

const std::string& Game::getPlayerName() const {
	return playerName;
}

void Game::setplayerPosition(float px, float py) {
	playerPositionX = px;
	playerPositionY = py;
}

float Game::getPositionX() const {
	return playerPositionX;
}

float Game::getPositionY() const {
	return playerPositionY;
}

void Game::setEnemyPosition(float px, float py) {
	enemyPositionX = px;
	enemyPositionY = py;
}

float Game::getEnemyPositionX() const {
	return enemyPositionX;
}

float Game::getEnemyPositionY() const {
	return enemyPositionY;
}

void Game::changeScene(Scene* newScene) {
	nextScene = newScene;
}

Game::~Game() {
	delete mainMenuScene;
	delete playScene;
	delete highScoreScene;
	delete loadingScene;
}