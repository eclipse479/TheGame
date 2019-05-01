#pragma once
#include "solidObject.h"
#include "Input.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "player.h"
class projectile :
	public solidObject
{
public:
	projectile();
	~projectile();

	//void playerShoot(aie::Renderer2D*	m_2dRenderer);

protected:
	aie::Texture* m_enemyBullet;
	aie::Texture* m_playerBullet;

private:
	int bulletType;
	int playerBullet_timer;
};

