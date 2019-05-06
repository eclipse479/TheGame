#pragma once
#include "solidObject.h"
#include "Texture.h"
#include "Renderer2D.h"
#include "Input.h"
class enemyShip :
	public solidObject
{
public:
	enemyShip();
	~enemyShip();
	void draw(aie::Renderer2D*	m_2dRenderer);
protected:
	aie::Texture* m_shipEnemy;
};

