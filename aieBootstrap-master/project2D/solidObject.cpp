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


bool solidObject::isColliding(solidObject* object1, solidObject* object2)
{
	float distance =
		sqrt((object1->getPositionX() - object2->getPositionX())*(object1->getPositionX() - object2->getPositionX()) +
		(object1->getPositionY() - object2->getPositionY())*(object1->getPositionY() - object2->getPositionY()));
	if (distance < (object1->getRadius() + object2->getRadius()))
	{
		return true;
	}
	else
	{
		return false;
	}
}