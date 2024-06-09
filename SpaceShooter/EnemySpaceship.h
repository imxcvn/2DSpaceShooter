#pragma once

class EnemySpaceship : public EnemyObject {
private:
	Game* game;
public:
	EnemySpaceship(Game* game);
	void update(float elapsed) override;
};