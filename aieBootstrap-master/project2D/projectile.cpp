#include "projectile.h"



projectile::projectile()
{
	
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
		positionX += deltaTime*300;
}


void projectile::createBullet(float posX, float posY, float radius, int bType, aie::Texture* const a_texture)
{
	positionX = posX;
	positionY = posY;
	objectRadius = radius;
	bulletType = bType;


}

