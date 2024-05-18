#pragma once

class EnemySpaceship : public GameObject {
private:
	sf::Sprite shape;
	sf::Texture shapeTexture;
	float vx = 0.f;
	float vy = 0.f;
	float sizeX;
	float sizeY;
	Game* game;
	int score;
public:
	EnemySpaceship(Game* game);
	int getScore() const;
	void update(float elapsed) override;
	void render(sf::RenderWindow& window) override;
	sf::Rect<float> getLocalBounds() const override;
};