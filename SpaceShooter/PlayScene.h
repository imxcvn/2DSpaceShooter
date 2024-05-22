#pragma once

class PlayScene : public Scene {
private:
	sf::RectangleShape background;
	sf::Texture mainTexture;
	std::vector<Projectile*> objects;
	std::vector<EnemyProjectile*> projectiles;
	std::vector<EnemySpaceship*> enemies;
	std::vector<Asteroid*> asteroids;
	std::vector<SmallAsteroid*> smallAsteroids;
	SpaceShip* spaceShip;
	sf::Clock enemySpawnClock;
	int score;
	sf::Text playerScore;
	sf::Font font;
	sf::Sprite hearts;
	float sizeX;
	float sizeY;
	float scaleX;
	float scaleY;
	sf::Sound endSound;
	sf::Sound enemySound;
	sf::Sound playerSound;
	sf::Sound scoreSound;
	sf::Sound shootSound;
public:
	PlayScene(float width, float height);
	void render(sf::RenderWindow& window) override;
	bool handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
	void update(float elapsed) override;
	void updateHearts(int hpPoints, sf::Sprite& hearts);
	void addEnemyProjectile(EnemyProjectile* projectile);
	void shown() override;
	void clear();
	~PlayScene();
};