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

//put the below code into the update() of application 2D to get a ship
/*float shipX = ship->get_positionX();
	float shipY = ship->get_positionY();
	float ship_rot = ship->get_rotation();
	float temp_speed = 100.0f;

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		shipX += cos(-ship_rot - 3.14159f * 0.5f) * temp_speed * deltaTime;
		shipY += -sin(-ship_rot - 3.14159f * 0.5f) * temp_speed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		shipX -= cos(-ship_rot - 3.14159f * 0.5f) * temp_speed * deltaTime;
		shipY -= -sin(-ship_rot - 3.14159f * 0.5f) * temp_speed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		ship_rot += 3.14159f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		ship_rot -= 3.14159f * deltaTime;

	ship->set_position(shipX, shipY);
	ship->set_rotation(ship_rot);*/