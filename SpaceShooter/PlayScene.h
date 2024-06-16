#pragma once


class PlayScene : public Scene {
private:
	sf::RectangleShape background;
	sf::RectangleShape stars;
	sf::RectangleShape stars20a;
	sf::RectangleShape stars20b;
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
	float stars20ScrollSpeed;
	template<Derived<GameObject> T> void renderGameObjects(sf::RenderWindow& window, std::vector<T*>& v);
	template<Derived<GameObject> T> void updateGameObjects(float elapsed, std::vector<T*>& v);
	template<class T> void deleteAllAndClear(std::vector<T*>& v);
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

template<Derived<GameObject> T> 
void PlayScene::renderGameObjects(sf::RenderWindow& window, std::vector<T*>& v) {
	for (int i = 0; i < v.size(); i++) {
		v[i]->render(window);
	}
}

template<Derived<GameObject> T> 
void PlayScene::updateGameObjects(float elapsed, std::vector<T*>& v) {
	for (int i = 0; i < v.size(); ) {
		v[i]->update(elapsed);
		if (v[i]->getShouldBeDestroyed()) {
			v.erase(v.begin() + i);
		}
		else
			i++;
	}
}

template<class T> 
void PlayScene::deleteAllAndClear(std::vector<T*>& v) {
	for (int i = 0; i < v.size(); i++) {
		delete v[i];
	}
	v.clear();
}