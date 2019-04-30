#pragma once
#include"Renderer2D.h"
#include"Font.h"
#include <cstring>
#include "Renderer2D.h"
#include "Application2D.h"
#include "Input.h"
class button
{
public:
	button(const char* buttonText, float x, float y, float width, float height, float red, float green, float blue);
	~button();


	bool update();

	void draw(aie::Renderer2D* renderer);

private:
	//Font and text for the button.
	aie::Font* m_font;
	char m_buttonText[64];
	//Button's position, width, and height.
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;
	//colours
	float r;
	float g;
	float b;

	float textWidth;
	float textHeight;
	float centredPosX;
	float centredPosY;

	float left;
	float right;
	float top;
	float bottom;

	int mouseX;
	int mouseY;
};

