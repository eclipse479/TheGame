#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "solidObject.h"
#include "background.h"
#include "player.h"
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
	m_enemyBulletSprite = new aie::Texture("../bin/textures/enemyProjectile.png"); // gets the texture for the enemies bullets
	m_playerBulletSprite = new aie::Texture("../bin/textures/playerProjectile.png"); // gets the texture for the player''s bullets
	the_background = new aie::Texture("../bin/textures/background.png"); // texture for the background
	enemySprite = new aie::Texture("../bin/textures/enemyShip.png");

	m_font = new aie::Font("../bin/font/ARCADE.ttf", 32);
	menu_font = new aie::Font("../bin/font/consolas_bold.ttf", 24);

	m_player = new player(200, 360, 50, 50, 25, m_shipTexture, (-3.1415f / 2));

	enemy = new enemyShip(100, 50, 50, 50, 25, enemySprite);

	heart = new aie::Texture("../bin/textures/heart.png");
	bones = new aie::Texture("../bin/textures/skullBones.png");

	m_background = new background();

	m_score = new score();
	m_score->scoreStartup();

	p_bullet = new projectile(0, -10, 35, 35, 10, 0, m_playerBulletSprite);
	m_timer = 0;
	return true;
}

void Application2D::shutdown()
{
	m_score->saveScore(); 
	delete m_player;
	delete enemy;
	delete m_shipTexture;
	delete m_playerBulletSprite;
	delete m_enemyBulletSprite;
	delete enemySprite;
	delete m_background;
	delete the_background;
	delete m_score;
	delete m_font;
	delete heart;
	delete bones;
	delete menu_font;
	delete p_bullet;
	delete m_2dRenderer;
	for (std::list<projectile*>::iterator iter = m_bullets.begin(); iter != m_bullets.end();)
	{
		projectile* deleteBullet = *iter;
		if (deleteBullet->isAlive())
		{
			delete deleteBullet;
		}
		iter++;
	}
	for (std::list<enemyShip*>::iterator iter = e_ships.begin(); iter != e_ships.end();)
	{
		enemyShip* deleteEnemy = *iter;
		if (deleteEnemy->isAlive())
		{
			delete deleteEnemy;
		}
		iter++;
	}
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
	if (m_background->getMenu() == 2 && m_player->getHealth() > 0)
	{
		m_background->update(deltaTime); // MOVES THE BACKGROUND
		m_player->player_update(deltaTime); // ALLOWS THE PLAYER TO MOVE
		m_score->scoreBoard(m_2dRenderer); // CHANGES TEH SCORE
		enemy->updateSpawnTimer(); // UPDATES THE ENEMY SPAN TIMER

		//----------------------------HOLDS THE PLAYER SHOOTING STATS---------------------------
		if (m_player->isShooting() && m_player->shootingTimer() < 0) //if the player shoots a bullet
		{
			m_player->setShooting(false);
			m_player->setshootingTimer(20); // reset time
			m_bullets.push_back(new projectile(m_player->getPositionX(), m_player->getPositionY(), p_bullet->getWidth(), p_bullet->getHeight(), p_bullet->getRadius(), 1, m_playerBulletSprite)); // creates bullets on space bar press
		}
		//----------------------------CONTROLS THE BULLETS BEHAVIOUR-----------------------------------------
		for (std::list<projectile*>::iterator iter = m_bullets.begin(); iter != m_bullets.end();)//handles bullets movement and collisions
		{
			projectile* bullet = *iter;
			if (bullet->isAlive()) {
				//check bullet against the player
				if (bullet->getBulletType() == 1)
				{
					bullet->player_bullet_update(deltaTime); // updates the bullets position
					//------------------------------------IF A BULLET COLLIDES WITH AN ENEMY SHIP----------------------
					for (std::list<enemyShip*>::iterator iter = e_ships.begin(); iter != e_ships.end(); iter++)//handles bullets movement and collisions
					{
						enemyShip* theEnemy = *iter;
						if (theEnemy->isAlive()) {
							if (isColliding(bullet, theEnemy))
							{
								m_score->scoreUpdate(2500);//adds score
								bullet->setBulletalive(false);//destroys the bullet
								theEnemy->setEnemyAlive(false);
							}
						}
					}

				}
				else if (bullet->getBulletType() == 2) //if enemy bullet
				{
					bullet->enemy_bullet_update(deltaTime);
					if (isColliding(bullet, m_player))
					{
						bullet->setBulletalive(false);//destroys the bullet
						m_player->addHealth(-1);
					}
				}
			}

			//-------------------------------- IF A PLAYER BULLET AND A ENEMY BULLET COLLIDE-------------------------
			for (std::list<projectile*>::iterator iter = m_bullets.begin(); iter != m_bullets.end();)//handles bullets movement and collisions
			{
				projectile* enemyBullet = *iter;
				if (bullet->getBulletType() == 1 && enemyBullet->getBulletType() == 2 && isColliding(bullet, enemyBullet))
				{
					bullet->setBulletalive(false);
					enemyBullet->setBulletalive(false);
				}
				iter++;
			}
			//------------------------------------CHECKS IF THE BULLETS ARE STILL ALIVE--------------------------
			bullet->bulletAliveCheck();
			if (!bullet->isAlive())
			{
				delete bullet;
				iter = m_bullets.erase(iter);
			}
			else
			{
				iter++;
			}
		} // end of bullet updates
		//------------------------------SPAWNS NEW ENEMIES-------------------------------
		if (enemy->getSpwanTimer() < 0)//creates a enemy at a random position
		{
			enemy->randomPath();
			e_ships.push_back(new enemyShip((900 + (enemy->getPath() * 100)), enemy->startingY(), enemy->getWidth(), enemy->getHeight(), enemy->getRadius(), enemySprite)); // creates enemies at certain intervals
			enemy->setSpawnTimer(25);
			m_score->scoreUpdate(50);
		}

		//------------------------------CONTROLS THE NEMIES-------------------------
		for (std::list<enemyShip*>::iterator iter = e_ships.begin(); iter != e_ships.end();)//handlesenemy ship movement and thier shooting timer
		{
			enemyShip* theEnemy = *iter;
			if (theEnemy->isAlive())
			{
				theEnemy->enemy_update(deltaTime); //updates the enemy position
				theEnemy->updateShootingTimer();
				if (theEnemy->getShootingTimer() < 0)
				{
					m_bullets.push_back(new projectile(theEnemy->getPositionX(), theEnemy->getPositionY(), p_bullet->getWidth(), p_bullet->getHeight(), p_bullet->getRadius(), 2, m_enemyBulletSprite)); // creates bullets on space bar press
					theEnemy->restartShootingTimer();
				}
			}
			theEnemy->enemyAliveCheck();
			if (!theEnemy->isAlive())
			{
				delete theEnemy;
				iter = e_ships.erase(iter);
			}
			else
			{
				iter++;
			}
		} // end of enemy ship updates


	}

	if (m_player->getHealth() <= 0)
	{
		m_background->setMenu(4);
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw()
{

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	//Draw the background
	m_background->draw(m_2dRenderer, the_background, menu_font);

	//draw the player
	m_player->draw(m_2dRenderer);
	m_2dRenderer->setRenderColour(1, 0, 0);
	m_2dRenderer->drawCircle(m_player->getPositionX(), m_player->getPositionY(), m_player->getRadius(), 20);
	for (std::list<projectile*>::iterator iter = m_bullets.begin(); iter != m_bullets.end(); iter++)
	{
		(*iter)->draw(m_2dRenderer);
	}

	for (std::list<enemyShip*>::iterator iter = e_ships.begin(); iter != e_ships.end(); iter++)
	{
		(*iter)->draw(m_2dRenderer);
	}
	// output some text, uses the last used colour
	if (m_background->getMenu() == 2) {
		char fps[32];
		m_2dRenderer->setRenderColour(1, 1, 1, 1);
		sprintf_s(fps, 32, "FPS: %i", getFPS());
		m_2dRenderer->drawText(m_font, fps, 8, 720 - 32);
		m_2dRenderer->drawText(m_font, "Press ESC to quit!", 8, 8);
		m_2dRenderer->drawText(m_font, "Health left: ", 350, 8);
		for (float i = 0; i < m_player->getHealth(); i++)
		{
			m_2dRenderer->drawSprite(heart, 530 + (i * 40), 20, 50, 50);
		}
		for (float i = 0; i < 5 - m_player->getHealth(); i++)
		{
			m_2dRenderer->drawSprite(bones, 690 - (i * 40), 20, 30, 30);
		}
		m_score->writeScore(m_2dRenderer);
	}
	if (m_background->getMenu() == 4)
	{
		m_score->writeFinalScore(m_2dRenderer);
	}
	// done drawing sprites
	m_2dRenderer->end();
}
