#include "Includes.h"

Game* Game::instance = nullptr;

Game::Game(sf::RenderWindow& window)
:
	gameWindow{window}
{
	instance = this;
}

void Game::initialize() {
	loadingScene = new LoadingScene{ 960, 720 };
	mainMenuScene = new MainMenuScene{ 960, 720 };
	highScoreScene = new HighScoreScene{ 960, 720, loadingScene };
	playScene = new PlayScene{ 960, 720 };
	currentScene = loadingScene;
	nextScene = nullptr;
}
void Game::update(float elapsed) {
	currentScene->update(elapsed);
	if (nextScene != nullptr) {
		currentScene = nextScene;
		nextScene = nullptr;
	}

	currentScene->shown();
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

const std::string& Game::getPlayerName() const {
	return playerName;
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