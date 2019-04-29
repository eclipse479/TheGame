#include "background.h"



background::background()
{
	m_background = new aie::Texture("../bin/textures/background.png");
}


background::~background()
{
}

void background::update(float deltaTime)
{
	posX -= 100.0 * deltaTime;
	posX2 -= 100.0 * deltaTime;

	if (posX <= -640)
		posX = 1920;
	if (posX2 <= -640)
		posX2 = 1920;
}

void background::draw(aie::Renderer2D*	m_2dRenderer)
{
	aie::Input* input = aie::Input::getInstance();
	//position and draw the ship
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
	m_2dRenderer->drawSprite(m_background, posX, 360, 1300, 720, 0, 100);
	m_2dRenderer->drawSprite(m_background, posX2, 360, 1300, 720, 0, 100);

}