#pragma once
class Game;

class Circle {
private:
	sf::CircleShape shape;
	float vx = 150.f;
	float vy = 200.f;
	float radius = 50.f;
	float px = 0.0;
	float py = 0.0;
	Game* game;
public:
	Circle(Game* game);
	void update(float elapsed);
	void render(sf::RenderWindow& window);
	void setRadius(float radius);
	void setColor(const sf::Color& color);
};

class PlayScene : public Scene {
private:
	sf::RectangleShape background;
	sf::Texture mainTexture;
	std::vector<Projectile*> objects;
public:
	PlayScene(float width, float height);
	void render(sf::RenderWindow& window) override;
	bool handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
	void update(float elapsed) override;
	~PlayScene();
};