#include "solidObject.h"
#include "Texture.h"
#include "..\dependencies\glm\glm\ext.hpp"



solidObject::solidObject()
{

}


solidObject::~solidObject()
{
}

//bool entity::isAlive()
//{
//
//}
void solidObject::setObject(float x, float y, float width, float height, float radius, aie::Texture* texture, float rotation)
{
	positionX = x;
	positionY = y;
	objectWidth = width;
	objectHeight = height;
	objectRadius = radius;
	objectRotation = rotation;
	objectTexture = texture;
}

float solidObject::getPositionX()
{
	return positionX;
}
float solidObject::getPositionY()
{
	return positionY;
}
float solidObject::getWidth()
{
	return objectWidth;
}
float solidObject::getHeight()
{
	return objectHeight;
}
float solidObject::getRadius()
{
	return objectRadius;
}


void solidObject::draw(aie::Renderer2D*	m_2dRenderer)
{
	aie::Input* input = aie::Input::getInstance();
	//position and draw the ship
	m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(objectTexture, positionX, positionY, objectWidth, objectHeight, objectRotation, 5);
}
