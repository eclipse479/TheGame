#include "enemyShip.h"



enemyShip::enemyShip()
{
	m_shipEnemy = new aie::Texture("../bin/textures/enemyShip.jpg"); // gets the ship texture/sprite
}


enemyShip::~enemyShip()
{
	delete m_shipEnemy;
}

void enemyShip::draw(aie::Renderer2D*	m_2dRenderer)
{
	aie::Input* input = aie::Input::getInstance();
	//position and draw the ship
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_shipEnemy, positionX, positionY, objectWidth, objectHeight, 0, 10);
}