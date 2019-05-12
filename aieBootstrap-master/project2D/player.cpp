#include "player.h"
#include<iostream>


player::player(float posX, float posY, float width, float height, float radius, aie::Texture* texture, float rotation)
{
	positionX = posX;
	positionY = posY;
	objectWidth = width;
	objectHeight = height;
	objectRadius = radius;
	objectTexture = texture;
	objectRotation = rotation;
}


player::~player()
{
}


//updating the player+boarder control
void player::player_update(float deltaTime) {
	aie::Input* input = aie::Input::getInstance();
	m_speed = 250;
	if (input->isKeyDown(aie::INPUT_KEY_UP) && positionY >= 720 - (objectHeight / 2))
	{
	}
	else if (input->isKeyDown(aie::INPUT_KEY_UP)) {
		positionY += m_speed * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN) && positionY <= 0 + (objectHeight / 2))
	{
	}
	else if (input->isKeyDown(aie::INPUT_KEY_DOWN)) {
		positionY -= m_speed * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_LEFT) && positionX <= 0 + (objectWidth / 2))
	{
	}
	else if (input->isKeyDown(aie::INPUT_KEY_LEFT)) {
		positionX -= m_speed * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) && positionX >= 800 - (objectWidth / 2))
	{
	}
	else if (input->isKeyDown(aie::INPUT_KEY_RIGHT)) {
		positionX += m_speed * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && shooting_timer < 0)
	{
		shooting = true;
	}

	if (shooting_timer > -2)
	{
		shooting_timer--;
	}
}

void player::setShooting(bool setshooting)
{
	shooting = setshooting;
}

bool player::isShooting()
{
	return shooting;
}

void player::setshootingTimer(int timer)
{
	shooting_timer = timer;
}

int player::shootingTimer()
{
	return shooting_timer;
}

void player::addHealth(int add)
{
	health += add;
}

int player::getHealth()
{
	return health;
}
