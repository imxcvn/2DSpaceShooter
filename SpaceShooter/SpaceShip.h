#pragma once

class SpaceShip : public GameObject {
private:
	sf::Sprite shape;
	sf::Texture shapeTexture;
	/*float vx = 200.f;
	float vy = 200.f;*/
	float px;
	float py;
	float sizeX;
	float sizeY;
	Game* game;
public:
	SpaceShip(Game* game);
	void update(float elapsed) override;
	void render(sf::RenderWindow& window) override;
	void setPosition(float x, float y);

};