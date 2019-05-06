#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "solidObject.h"
#include "background.h"
#include "player.h"
#include "rock.h"
#include "projectile.h"
#include "score.h"
#include "enemyShip.h"


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() { // creates things for the game

	m_2dRenderer = new aie::Renderer2D();

	m_shipTexture = new aie::Texture("../bin/textures/ship.png"); // gets the ship texture/sprite
	m_enemyBullet = new aie::Texture("../bin/textures/enemyBullet.png"); // gets the texture for the enemies bullets
	m_playerBullet = new aie::Texture("../bin/textures/playerProjectile.png"); // gets the texture for the player''s bullets
	the_background = new aie::Texture("../bin/textures/background.png"); // texture for the background

	m_font = new aie::Font("../bin/font/ARCADE.ttf", 32);


	m_player = new player();
	m_player->setObject(200, 360, 50, 50, 25,m_shipTexture, (-3.1415 / 2));
	
	m_rock = new rock();
	m_rock->setObject(300, 300, 50, 50, 30,m_enemyBullet);

	m_background = new background();

	m_score = new score();
	m_score->scoreStartup();


	p_bullet = new projectile();
	p_bullet->setObject(100, 100, 35, 35, 10, m_playerBullet);
	m_timer = 0;
	return true;
}

void Application2D::shutdown() 
{	
	delete m_2dRenderer;
	delete m_player;
	delete m_shipTexture;
	delete m_playerBullet;
	delete m_enemyBullet;
	delete m_background;
	delete the_background;
	delete m_score;
	delete m_font;
	delete m_rock;
	delete p_bullet;
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



void Application2D::update(float deltaTime) 
{
	// input example
	aie::Input* input = aie::Input::getInstance();
	if (m_background->getMenu() == 2)
	{
		m_background->update(deltaTime);
		m_player->update(deltaTime);
		m_timer += deltaTime;
		m_score->scoreBoard(m_2dRenderer);
		p_bullet->player_bullet_update(deltaTime);

			if (m_player->isShooting() && m_player->shootingTimer()<0)
			{
				m_player->setShooting(false);
				m_player->setshootingTimer(50);
				std::cout << "shot fired\n";
				p_bullet->setObject(m_player->getPositionX(), m_player->getPositionY(), 40, 40, 12, m_playerBullet);
				m_score->scoreUpdate(25000);
			}
	}
	
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
	m_background->draw(m_2dRenderer, the_background);

	//draw the player
	m_player->draw(m_2dRenderer);
	p_bullet->draw(m_2dRenderer);
	m_2dRenderer->setRenderColour(1, 0, 0);
	m_2dRenderer->drawCircle(m_player->getPositionX(), m_player->getPositionY(), m_player->getRadius(),20);

	m_2dRenderer->setRenderColour(0, 0, 1);
	m_2dRenderer->drawCircle(m_rock->getPositionX(), m_rock->getPositionY(), m_rock->getRadius(), 20);

	m_2dRenderer->setRenderColour(0, 1, 0);
	m_2dRenderer->drawCircle(p_bullet->getPositionX(), p_bullet->getPositionY(), p_bullet->getRadius(), 10);

	if (isColliding(m_player, m_rock))
	{
		std::cout << "collision\n";
		m_score->scoreUpdate(-100);
	}

	// output some text, uses the last used colour
	if (m_background->getMenu() == 2) {
		char fps[32];
		m_2dRenderer->setRenderColour(1, 1, 1, 1);
		sprintf_s(fps, 32, "FPS: %i", getFPS());
		m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
		m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);
		m_score->writeScore(m_2dRenderer);
	}
	// done drawing sprites
	m_2dRenderer->end();
}
