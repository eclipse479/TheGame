#include "projectile.h"



projectile::projectile()
{
	m_enemyBullet = new aie::Texture("../bin/textures/enemyBullet.png"); // gets the texture for the enemies bullets
	m_playerBullet = new aie::Texture("../bin/textures/playerBullet.png"); // gets the texture for the player''s bullets
}


projectile::~projectile()
{

}
