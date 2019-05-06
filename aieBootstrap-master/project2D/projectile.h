#pragma once
#include "solidObject.h"
#include "Input.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "player.h"

class player;

class projectile :
	public solidObject
{
public:
	projectile();
	~projectile();
	void createBullet(float posX, float posY, float radius, int bType, aie::Texture* const a_texture);
	void setBullettype(int bulletType);
	int getBulletType();
	void player_bullet_update(float deltaTime);
protected:
	
private:
	int bulletType;
	int playerBullet_timer;
};

