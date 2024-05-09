#include "Includes.h"

PlayScene::PlayScene(float width, float height) {
	background.setSize(sf::Vector2f(960, 720));
	mainTexture.loadFromFile("Texture/SpaceBackground4.png");
	background.setTexture(&mainTexture);

	backgroundStars.setSize(sf::Vector2f(960, 720));
	starTexture.loadFromFile("Texture/stars4.png");
	backgroundStars.setTexture(&starTexture);

	backgroundStars2.setSize(sf::Vector2f(960, 720));
	starTexture2.loadFromFile("Texture/stars5.png");
	backgroundStars2.setTexture(&starTexture2);

	Projectile* object = new Projectile{ Game::instance };

	objects.push_back(object);
	spaceShip = new SpaceShip{ Game::instance };
	spaceShip->setPosition(300, 650);
}

void PlayScene::render(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(backgroundStars);
	window.draw(backgroundStars2);
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->render(window);
	}
	spaceShip->render(window);
}

bool PlayScene::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			Game::instance->changeScene(Game::instance->mainMenuScene);
			return true;
		}
		if (event.key.code == sf::Keyboard::Space) {
			Projectile* object = new Projectile{ Game::instance };
			objects.push_back(object);
		}
	}
	return false;
}

void PlayScene::update(float elapsed) {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->update(elapsed);
	}
	spaceShip->update(elapsed);
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