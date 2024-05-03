#pragma once
class Game;

class GameObject {
private:
	sf::Sprite shape;
	sf::Texture shapeTexture;
	float vx = 150.f;
	float vy = 200.f;
	float px = 0.0;
	float py = 0.0;
	float desiredWidth = 100.f;
	float desiredHeight = 100.f;
	float scaleX;
	float scaleY;
	Game* game;
public:
	GameObject(Game* game);
	void update(float elapsed);
	void render(sf::RenderWindow& window);
};