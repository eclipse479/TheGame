#pragma once
#include "solidObject.h"
#include "Texture.h"
#include "Renderer2D.h"
#include "Input.h"
class enemyShip : public solidObject
{
public:
	enemyShip();

	~enemyShip();

	void setSpawnTimer(int timer);
	int getSpwanTimer();
	void setShootingTimer(int timer);
	void update();
	bool spawnEnemy();
private:
	int spawn_timer = 50;
	int shooting_timer = 166;
};