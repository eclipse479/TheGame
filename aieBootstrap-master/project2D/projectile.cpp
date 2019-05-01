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

//void projectile::playerShoot(aie::Renderer2D*	m_2dRenderer)
//{
//	aie::Input* input = aie::Input::getInstance();
//	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && playerBullet_timer < 0)
//	{
//		m_2dRenderer->drawSprite(m_playerBullet, 500, 500, 20, 20);
//		playerBullet_timer = 50;
//	}
//	playerBullet_timer--;
//}