#pragma once

class PlayScene : public Scene {
private:
	sf::RectangleShape background;
	sf::Texture mainTexture;
	std::vector<Projectile*> objects;
	std::vector<EnemyProjectile*> projectiles;
	std::vector<EnemySpaceship*> enemies;
	std::vector<Asteroid*> asteroids;
	SpaceShip* spaceShip;
	sf::Clock enemySpawnClock;
	sf::Clock projectileSpawnClock;
	int score;
	sf::Text playerScore;
	sf::Font font;
	sf::Sprite hearts;
	sf::Texture heartsTexture;
	float sizeX;
	float sizeY;
	float scaleX;
	float scaleY;
public:
	PlayScene(float width, float height);
	void render(sf::RenderWindow& window) override;
	bool handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
	void update(float elapsed) override;
	void shown() override;
	void clear();
	~PlayScene();
};