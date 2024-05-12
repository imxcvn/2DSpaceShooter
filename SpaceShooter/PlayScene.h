#pragma once

class PlayScene : public Scene {
private:
	sf::RectangleShape background;
	sf::Texture mainTexture;
	sf::RectangleShape backgroundStars;
	sf::Texture starTexture;
	sf::RectangleShape backgroundStars2;
	sf::Texture starTexture2;
	std::vector<Projectile*> objects;
	std::vector<EnemyProjectile*> projectiles;
	std::vector<EnemySpaceship*> enemies;
	SpaceShip* spaceShip;
public:
	PlayScene(float width, float height);
	void render(sf::RenderWindow& window) override;
	bool handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
	void update(float elapsed) override;
	void shown() override;
	void clear();
	~PlayScene();
};