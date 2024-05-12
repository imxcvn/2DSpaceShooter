#pragma once

class SpaceShip : public GameObject {
private:
	sf::Sprite shape;
	sf::Texture shapeTexture;
	float sizeX;
	float sizeY;
	Game* game;
public:
	SpaceShip(Game* game);
	void update(float elapsed) override;
	void render(sf::RenderWindow& window) override;
	void setPosition(float x, float y);
};