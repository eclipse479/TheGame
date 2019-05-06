#include "projectile.h"



projectile::projectile()
{
	m_enemyBullet = new aie::Texture("../bin/textures/enemyBullet.png"); // gets the texture for the enemies bullets
	m_playerBullet = new aie::Texture("../bin/textures/playerBullet.png"); // gets the texture for the player''s bullets
}


projectile::~projectile()
{
	delete m_enemyBullet;
	delete m_playerBullet;
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
	if (bulletType == 1)
	{
		positionX += deltaTime*100;
	}
	else if (bulletType == 2)
	{
		positionX -= deltaTime * 100;
	}
	if (positionX < -20 || positionX > 1300)
	{
	
	}
}


void projectile::createBullet(float posX, float posY, float radius, int bType, aie::Texture* const a_texture)
{
	positionX = posX;
	positionY = posY;
	objectRadius = radius;
	bulletType = bType;


}

