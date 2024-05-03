#include "Includes.h"

Game* Game::instance = nullptr;

Game::Game() {
	instance = this;
}

void Game::initialize() {
	mainMenuScene = new MainMenuScene{ 960, 720 };
	highScoreScene = new HighScoreScene{ 960, 720 };
	playScene = new PlayScene{ 960, 720 };
	currentScene = mainMenuScene;
	nextScene = nullptr;
}
void Game::update(float elapsed) {
	currentScene->update(elapsed);
	if (nextScene != nullptr) {
		currentScene = nextScene;
		nextScene = nullptr;
	}
}
void Game::render(sf::RenderWindow& window) {
	currentScene->render(window);
}
bool Game::handleEvent(const sf::Event& e, sf::RenderWindow& window) {
	return currentScene->handleEvent(e, window);
}

void Game::changeScene(Scene* newScene) {
	nextScene = newScene;
}

Game::~Game() {
	delete mainMenuScene;
	delete playScene;
	delete highScoreScene;
}