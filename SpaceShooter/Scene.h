#pragma once

class Scene {
public:
	virtual void update(float elapsed) {}
	virtual void render(sf::RenderWindow& window) {}
	virtual void shown() {}
	virtual bool handleEvent(const sf::Event& e, sf::RenderWindow& window) {
		return false;
	}
	virtual ~Scene() {}
};