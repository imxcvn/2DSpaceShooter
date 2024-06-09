#pragma once

class PlayScene : public Scene {
private:
	sf::RectangleShape background;
	sf::RectangleShape stars;
	sf::RectangleShape stars20;
	sf::Texture mainTexture;
	std::vector<Projectile*> objects;
	std::vector<EnemyProjectile*> projectiles;
	std::vector<EnemyObject*> enemies;
	SpaceShip* spaceShip = nullptr;
	sf::Clock enemySpawnClock;
	sf::Clock secondEnemySpawnClock;
	int score;
	sf::Text playerScore;
	sf::Font font;
	sf::Sprite heart1;
	sf::Sprite heart2;
	sf::Sprite heart3;
	sf::Sound endSound;
	sf::Sound enemySound;
	sf::Sound playerSound;
	sf::Sound scoreSound;
	sf::Sound shootSound;
	sf::Sound music;
public:
	PlayScene(float width, float height);
	void render(sf::RenderWindow& window) override;
	bool handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
	void update(float elapsed) override;
	void addEnemyProjectile(EnemyProjectile* projectile);
	void shown() override;
	void clear();
	void gameOver();
	void setScore(int score);
	void addScore(int score);
	~PlayScene();
};