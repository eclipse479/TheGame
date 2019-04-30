#pragma once
#include "player.h"
#include "Application.h"
#include "Renderer2D.h"
#include "game_object.h"
#include "background.h"

class Application2D : public aie::Application
{
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Texture*		m_STexture;

	float m_timer;
	game_object *ship;
	player *m_player;
	background *m_background;

};