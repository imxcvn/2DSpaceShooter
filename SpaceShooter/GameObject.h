#pragma once
class Game;

class GameObject {
public:
	virtual void update(float elapsed) {}
	virtual void render(sf::RenderWindow& window) {}
	virtual ~GameObject() {}
};