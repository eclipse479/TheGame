#include "enemyShip.h"
#include <iostream>


enemyShip::enemyShip()
{
}
	


enemyShip::~enemyShip()
{
}

void enemyShip::setSpawnTimer(int timer)
{
	spawn_timer = timer;
}

int enemyShip::getSpwanTimer()
{
	return spawn_timer;
}

void enemyShip::setShootingTimer(int timer)
{
	shooting_timer = timer;
}

bool enemyShip::spawnEnemy()
{
	return true;
}

void enemyShip::update()
{
	spawn_timer--;
}