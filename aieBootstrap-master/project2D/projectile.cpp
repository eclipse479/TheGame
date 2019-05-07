#include "projectile.h"



projectile::projectile(float posX, float posY, float width, float height, float radius, int bType, aie::Texture* texture)
{
	positionX = posX;
	positionY = posY;
	objectWidth = width;
	objectHeight = height;
	objectRadius = radius;
	objectTexture = texture;
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




