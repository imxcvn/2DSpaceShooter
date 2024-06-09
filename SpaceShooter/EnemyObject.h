#pragma once
class Game;

class EnemyObject : public GameObject {
protected:
	sf::Texture shapeTexture;
	sf::Sprite shape;
	float vx = 0.f;
	float vy = 0.f;
	float sizeX;
	float sizeY;
	int score;
	int damage;
	float elapsedSum;
	bool canGetDestroyedByProjectile = false;
public:
	int getScore() const { return score; };
	int getDamage() const { return damage; };
	bool getCanBeDestroyedByProjectile() const;
	float getPositionX() const override;
	float getPositionY() const override;
	void update(float elapsed) override;
	void render(sf::RenderWindow& window) override;
	sf::Rect<float> getLocalBounds() const override;
};
