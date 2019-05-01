#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "solidObject.h"
#include "background.h"
#include "player.h"
#include "rock.h"


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() { // creates things for the game

	m_2dRenderer = new aie::Renderer2D();

	m_player = new player();
	m_player->setObject(200, 360, 50, 50, 25);
	
	m_rock = new rock();
	m_rock->setObject(300, 300, 50, 50, 30);

	m_background = new background();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_playerBullet = new aie::Texture("../bin/textures/playerBullet.png");

	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{	
	delete m_player;
	delete m_font;
	delete m_2dRenderer;
	delete m_background;
	delete m_rock;
	delete m_playerBullet;
}

bool Application2D::isColliding(solidObject* object1, solidObject* object2)
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

void playerShoot(aie::Renderer2D* m_2dRenderer, player* player)
{
	aie::Input* input = aie::Input::getInstance();
	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && player->shootingTimer() < 0)
	{
		m_2dRenderer->setRenderColour(0, 1, 0, 1);
		m_2dRenderer->drawCircle(player->getPositionX(), player->getPositionY(), 100, 0);
		player->setshootingTimer(50);
		std::cout << "shot fired\n";
	}
	std::cout << player->shootingTimer() << std::endl;
}

void Application2D::update(float deltaTime) 
{
	// input example
	aie::Input* input = aie::Input::getInstance();
	if (m_background->getMenu() == 2)
	{
		m_background->update(deltaTime);
		m_player->update(deltaTime);
		m_timer += deltaTime;
	}
	playerShoot(m_2dRenderer, m_player);
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//Draw the background
	m_background->draw(m_2dRenderer);

	//draw the player
	m_player->draw(m_2dRenderer);
	m_2dRenderer->setRenderColour(1, 0, 0);
	m_2dRenderer->drawCircle(m_player->getPositionX(), m_player->getPositionY(), m_player->getRadius(),20);

	m_2dRenderer->setRenderColour(0, 0, 1);
	m_2dRenderer->drawCircle(m_rock->getPositionX(), m_rock->getPositionY(), m_rock->getRadius(), 20);

	if (isColliding(m_player, m_rock))
	{
		std::cout << "collision\n";
	}

	// output some text, uses the last used colour
	char fps[32];
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}
