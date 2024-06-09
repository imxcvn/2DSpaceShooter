#pragma once

class EnemySpaceship2 : public EnemyObject {
private:
	Game* game;
public:
	EnemySpaceship2(Game* game);
	void update(float elapsed) override;
};