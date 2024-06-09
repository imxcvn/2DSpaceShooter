#pragma once

class SmallAsteroid : public EnemyObject {
private:
	Game* game;
public:
	SmallAsteroid(Game* game);
};