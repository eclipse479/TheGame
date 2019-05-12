#include "projectile.h"



projectile::projectile(float posX, float posY, float width, float height, float radius, int bType, aie::Texture* texture)
{
	positionX = posX;
	positionY = posY;
	objectWidth = width;
	objectHeight = height;
	objectRadius = radius;
	objectTexture = texture;
	bulletType = bType;
}


projectile::~projectile()
{
}

void projectile::setBullettype(int Type)
{
	bulletType = Type;
}



int projectile::getBulletType()
{
	return bulletType;
}

void projectile::player_bullet_update(float deltaTime)
{
	positionX += deltaTime * 350;
}

void projectile::enemy_bullet_update(float deltaTime)
{
	positionX -= deltaTime * 350;
}

bool projectile::isAlive()
{
	return alive;
}

void projectile::bulletAliveCheck()
{
	if (positionX < -10)
	{
		alive = false;
	}
	if (positionX > 1300)
	{
		alive = false;
	}
}

void projectile::setBulletalive(bool change)
{
	alive = change;
}