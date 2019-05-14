#include "projectile.h"



projectile::projectile(float posX, float posY, float width, float height, float radius, int bType, aie::Texture* texture, float rotation)
{
	positionX = posX;
	positionY = posY;
	objectWidth = width;
	objectHeight = height;
	objectRadius = radius;
	objectTexture = texture;
	bulletType = bType;
	objectRotation = rotation;
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

void projectile::bullet_update(float deltaTime)
{
	if (bulletType == 1) {
		positionX += deltaTime * 350;
	}
	else if (bulletType == 2)
	{
		positionX -= deltaTime * 350;
	}
	else if (bulletType == 3)
	{
		positionX -= deltaTime * 150;
	}
	else if (bulletType == 4)
	{
		positionX -= deltaTime * 350;
		positionY += deltaTime * 50;
	}
	else if (bulletType == 5)
	{
		positionX -= deltaTime * 350;
		positionY -= deltaTime * 50;
	}
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