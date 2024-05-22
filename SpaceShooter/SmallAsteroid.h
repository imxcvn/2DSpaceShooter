#pragma once

class SmallAsteroid : public GameObject {
private:
	sf::Sprite shape;
	sf::Texture shapeTexture;
	float vx = 0.f;
	float vy = 0.f;
	float sizeX;
	float sizeY;
	Game* game;
	int damage;
public:
	SmallAsteroid(Game* game);
	int getDamage() const;
	void update(float elapsed) override;
	void render(sf::RenderWindow& window) override;
	sf::Rect<float> getLocalBounds() const override;
};