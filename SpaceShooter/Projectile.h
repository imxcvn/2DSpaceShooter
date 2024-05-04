#pragma once
class Game;

class Projectile : public GameObject {
private:
	sf::Sprite shape;
	sf::Texture shapeTexture;
	float vx = 200.f;
	float vy = 200.f;
	float px = 0.0;
	float py = 0.0;
	float scaleX;
	float scaleY;
	Game* game;
public:
	Projectile(Game* game);
	void update(float elapsed) override;
	void render(sf::RenderWindow& window) override;
};