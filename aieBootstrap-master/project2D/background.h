#pragma once
#include "Renderer2D.h"
#include "Texture.h"
#include "Input.h"
#include "button.h"
class background
{
public:
	background();
	~background();
	virtual void update(float deltaTime);

	virtual void draw(aie::Renderer2D*	m_2dRenderer);

	int getMenu();

protected:

	aie::Texture* m_background;
	button* play_button;
	button* options_button;
	button* menu_button;
private:
	aie::Font* menu_font;
	char m_menuText[64];
	int menu = 1;
	float posX = 640;
	float posX2 = 1920;
};

