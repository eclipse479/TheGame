#pragma once
#include "solidObject.h"
#include "Texture.h"
#include "Renderer2D.h"
#include "Input.h"
class enemyShip : public solidObject
{
public:
	enemyShip(float posX, float posY, float width, float height, float radius, aie::Texture* texture, int newPath);

	~enemyShip();
	//spawning functions
	void setSpawnTimer(int timer);
	int getSpwanTimer();
	//shooting functions
	void restartShootingTimer(int timer);
	void updateShootingTimer();
	int getShootingTimer();
	//enemy position functions
	void enemy_update(float deltaTime);
	void randomPath();
	float getPath();
	float startingY();
	//enemy spawning
	void  updateSpawnTimer();
	//is the enemy alive
	void enemyAliveCheck();
	bool isAlive();
	void setEnemyAlive(bool change);

private:
	float startY;
	int spawn_timer = 250;
	int shooting_timer = 40;
	bool alive = true;
	int path;
};