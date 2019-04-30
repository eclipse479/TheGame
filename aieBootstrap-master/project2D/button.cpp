#include "button.h"
#include <cstring>
#include "Renderer2D.h"

button::button(const char* buttonText, float x, float y, float width, float height, float red, float green, float blue)
{
	//Store the text that will appear on the button.
	strcpy_s(m_buttonText, 64, buttonText);
	//Load a font to use to display the text.
	m_font = new aie::Font("./font/consolas.ttf", 24);
	//Store the button's position, width, and height.
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;

	r = red;
	g = green;
	b = blue;

	textWidth = m_font->getStringWidth(m_buttonText);
	textHeight = m_font->getStringHeight(m_buttonText);
	centredPosX = m_posX - (textWidth * 0.5f) + 2;
	centredPosY = m_posY - (textHeight * 0.5f) + 5;
}


button::~button()
{
	delete m_font;
}

void button::draw(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(r, g, b, 1.0f);
	renderer->drawBox(m_posX, m_posY, m_width, m_height);
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);
}