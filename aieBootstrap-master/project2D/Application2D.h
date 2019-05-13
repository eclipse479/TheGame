#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include <iostream>
#include <list>
#include <ctime>

class game_object;
class button;
class player;
class background;
class solidObject;
class score;
class projectile;
class enemyShip;

class Application2D : public aie::Application
{
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	bool isColliding(solidObject* object1, solidObject* object2);
protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Texture*       m_playerBulletSprite;
	aie::Texture*       m_enemyBulletSprite;
	aie::Texture*       the_background;
	aie::Texture*       enemySprite;
	aie::Texture*       heart;
	aie::Texture*       bones;
	aie::Font*			m_font;
	aie::Font*          menu_font;

	float m_timer;
	game_object*	 ship;
	player*		 	 m_player;
	background*		 m_background;
	button*			 m_button;
	score*           m_score;
	enemyShip*       enemy;
	projectile*      p_bullet;
	std::list<projectile*> m_bullets;
	std::list<enemyShip*>  e_ships;
};