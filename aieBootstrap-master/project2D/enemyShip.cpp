#include "enemyShip.h"
#include <iostream>
#include <ctime>

enemyShip::enemyShip(float posX, float posY, float width, float height, float radius, aie::Texture* texture, int newPath)
{
	positionX = posX;
	positionY = posY;
	objectWidth = width;
	objectHeight = height;
	objectRadius = radius;
	objectTexture = texture;
	path = newPath;
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
void  enemyShip::updateSpawnTimer()
{
	if (spawn_timer > -2)
	{
		spawn_timer--;
	}
}


float enemyShip::getPath()
{
	return path;
}
void enemyShip::randomPath()
{
	path = rand() % 4;

}


void enemyShip::restartShootingTimer(int timer)
{
	shooting_timer = (rand()%timer) + timer;
}
int enemyShip::getShootingTimer()
{
	return shooting_timer;
}
void enemyShip::updateShootingTimer()
{
	if (shooting_timer > -2)
	{
		shooting_timer--;
	}
}


void enemyShip::enemy_update(float deltaTime)
{

	if (positionX == 900 || positionX == 1100)
	{
		positionY += deltaTime * 200;
	}
	else if (positionX == 1000 || positionX == 1200)
	{
		positionY -= deltaTime * 200;
	}
}

float enemyShip::startingY()
{
	if (path == 1 || path == 3)
	{
		startY = 770;
		return startY;
	}
	else
	{
		startY = -50;
		return startY;
	}
}


bool enemyShip::isAlive()
{
	return alive;
}
void enemyShip::enemyAliveCheck()
{
	if (positionY > 800)
	{
		alive = false;
	}
	if (positionY < -100)
	{
		alive = false;
	}
}
void enemyShip::setEnemyAlive(bool change)
{
	alive = change;
}