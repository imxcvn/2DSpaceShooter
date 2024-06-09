#pragma once

class Asteroid : public EnemyObject {
private:
	Game* game;
public:
	Asteroid(Game* game);
};