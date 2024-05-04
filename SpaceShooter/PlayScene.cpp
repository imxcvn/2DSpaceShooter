#include "Includes.h"

PlayScene::PlayScene(float width, float height) {
	background.setSize(sf::Vector2f(4600, 2600));
	mainTexture.loadFromFile("Texture/SpaceBackground1.png");
	background.setTexture(&mainTexture);

	Projectile* object = new Projectile{ Game::instance };

	objects.push_back(object);

}

void PlayScene::render(sf::RenderWindow& window) {
	window.draw(background);
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->render(window);
	}
}

bool PlayScene::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			Game::instance->changeScene(Game::instance->mainMenuScene);
			return true;
		}
	}
	return false;
}

void PlayScene::update(float elapsed) {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->update(elapsed);
	}
}

Circle::Circle(Game* game) {
	shape.setFillColor(sf::Color::Red);
	shape.setRadius(radius);
	this->game = game;
}

void Circle::update(float elapsed) {
	float deltaX = vx * elapsed / 1000;
	float deltaY = vy * elapsed / 1000;
	px += deltaX;
	py += deltaY;
	if (py + radius >= game->screenSize.y && vy > 0) {

		vy = -vy;
	}
	else if (py - radius <= 0 && vy < 0) {
		vy = -vy;
	}
	if (px + radius >= game->screenSize.x && vx > 0) {
		vx = -vx;
	}
	else if (px - radius <= 0 && vx < 0) {
		vx = -vx;
	}
}

void Circle::render(sf::RenderWindow& window) {
	shape.setPosition({ px - radius,py - radius });
	window.draw(shape);
}

void Circle::setRadius(float radius) {
	this->radius = radius;
	shape.setRadius(radius);
}

void Circle::setColor(const sf::Color& color) {
	shape.setFillColor(color);
}

PlayScene::~PlayScene() {
	for (int i = 0; i < objects.size(); i++) {
		delete objects[i];
	}
}