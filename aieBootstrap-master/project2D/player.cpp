#include "player.h"



player::player()
{
	m_shipTexture = new aie::Texture("../bin/textures/ship.png"); // gets the ship texture/sprite

}


player::~player()
{
	delete m_shipTexture;
}


//updating the player+boarder control
void player::update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();
	m_speed = 150;
	if (input->isKeyDown(aie::INPUT_KEY_UP) && positionY >= 720 - (objectHeight / 2))
	{	}
	else if (input->isKeyDown(aie::INPUT_KEY_UP)) {
		positionY += m_speed * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN) && positionY <= 0 + (objectHeight / 2))
	{}
	else if (input->isKeyDown(aie::INPUT_KEY_DOWN)) {
		positionY -= m_speed * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_LEFT) && positionX <= 0 + (objectWidth / 2))
	{	}
	else if (input->isKeyDown(aie::INPUT_KEY_LEFT)) {
		positionX -= m_speed * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) && positionX >= 1280 - (objectWidth / 2))
	{	}
	else if (input->isKeyDown(aie::INPUT_KEY_RIGHT)) {
		positionX += m_speed * deltaTime;
	}

	//if (input->isKeyDown(aie::INPUT_KEY_DOWN) && input->isKeyDown(aie::INPUT_KEY_RIGHT))
	//rotation = -3*PI/4;
	//if (input->isKeyDown(aie::INPUT_KEY_UP) && input->isKeyDown(aie::INPUT_KEY_RIGHT))
	//rotation = -PI / 4;
	//if (input->isKeyDown(aie::INPUT_KEY_DOWN) && input->isKeyDown(aie::INPUT_KEY_LEFT))
	//rotation = 3*PI / 4;
	//if (input->isKeyDown(aie::INPUT_KEY_UP) && input->isKeyDown(aie::INPUT_KEY_LEFT))
	//rotation = PI / 4;


}

void player::draw(aie::Renderer2D*	m_2dRenderer)
{
	aie::Input* input = aie::Input::getInstance();
	//position and draw the ship
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
	m_2dRenderer->drawSprite(m_shipTexture, positionX, positionY, objectWidth, objectHeight, rotation, 1);
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
}
