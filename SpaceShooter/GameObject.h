#pragma once
class Game;

class GameObject {
public:
	virtual void update(float elapsed) {}
	virtual void render(sf::RenderWindow& window) {}
	virtual float getPositionX() const { return px; }
	virtual float getPositionY() const { return py; }
	virtual ~GameObject() {}
	void destroyLater() { shouldBeDestroyed = true; }
	virtual sf::Rect<float> getLocalBounds() const { return { 0, 0, 0, 0 }; }
	sf::Rect<float> getGlobalBounds() const;
	bool getShouldBeDestroyed() const { return shouldBeDestroyed; }
private:
	bool shouldBeDestroyed = false;
protected:
	float px;
	float py;
};
