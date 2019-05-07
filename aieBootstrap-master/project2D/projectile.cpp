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




