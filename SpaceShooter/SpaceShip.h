#pragma once

class SpaceShip : public GameObject {
private:
	sf::Sprite shape;
	int hpPoints;
	float sizeX;
	float sizeY;
	Game* game;
	float blinkingTime = 0;
	bool isShot;
	int blinkCounter = 0;
public:
	SpaceShip(Game* game);
	void update(float elapsed) override;
	void render(sf::RenderWindow& window) override;
	void setPosition(float x, float y);
	void decreaseHealth(int damage);
	void startBlinking();
	int getHpPoints() const;
	//void subtracktHP(int damage);
	sf::Rect<float> getLocalBounds() const override;
	friend class PlayScene;
};