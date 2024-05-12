#pragma once
class Game;

class EnemyProjectile : public GameObject {
private:
	sf::Sprite shape;
	sf::Texture shapeTexture;
	float vx = 0.f;    
	float vy = 200.f;     
	float sizeX;
	float sizeY;
	Game* game;
public:
	EnemyProjectile(Game* game);
	void update(float elapsed) override;
	void render(sf::RenderWindow& window) override;
};