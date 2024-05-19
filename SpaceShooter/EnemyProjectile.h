#pragma once
class Game;

class EnemyProjectile : public GameObject {
private:
	sf::Sprite shape;
	sf::Texture shapeTexture;
	float vx = 0.f;    
	float vy = 250.f;     
	float sizeX;
	float sizeY;
	int damage;
	Game* game;
public:
	EnemyProjectile(Game* game);
	void update(float elapsed) override;
	void setDamage(int points);
	int getDamage() const;
	void render(sf::RenderWindow& window) override;
	sf::Rect<float> getLocalBounds() const override;
};