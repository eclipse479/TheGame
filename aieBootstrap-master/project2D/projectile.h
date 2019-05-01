#pragma once
#include "solidObject.h"
#include "Input.h"
#include "Renderer2D.h"
#include "Texture.h"
class projectile :
	public solidObject
{
public:
	projectile();
	~projectile();
protected:
	aie::Texture* m_enemyBullet;
	aie::Texture* m_playerBullet;

private:
	int bulletType;

};

