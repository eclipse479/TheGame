#pragma once
#include "solidObject.h"
#include "Input.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "player.h"

class player;

class projectile : public solidObject
{
public:
	projectile(float posX, float posY, float width, float height, float radius, int bType, aie::Texture* texture);
	~projectile();
	void setBullettype(int bulletType);
	int getBulletType();
	void player_bullet_update(float deltaTime);
	void enemy_bullet_update(float deltaTime);
	bool isAlive();
	void bulletAliveCheck();
	void setBulletalive(bool change);
protected:

private:
	int bulletType = 0;
	bool alive = true;
};

