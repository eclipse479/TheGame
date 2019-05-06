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

void solidObject::setObject(float x, float y, float width, float height, float radius)
{
	positionX = x;
	positionY = y;
	objectWidth = width;
	objectHeight = height;
	objectRadius = radius;
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



