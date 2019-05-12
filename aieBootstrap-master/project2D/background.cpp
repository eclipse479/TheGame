#include "background.h"
#include <cstring>
#include "player.h"
#include "score.h"

background::background()
{
	play_button = new button("PLAY", 320, 360, 150, 100, 0, 0.7f, 0);
	options_button = new button("CONTROLS", 960, 360, 150, 100, 1, 0, 0);
	menu_button = new button("MAIN MENU", 640, 180, 150, 100, 0, 0, 1);
}

background::~background()
{
	delete play_button;
	delete menu_button;
	delete options_button;
}

void background::update(float deltaTime)
{
	posX -= 100.0f * deltaTime;
	posX2 -= 100.0f * deltaTime;

	if (posX <= -640)
		posX = 1920;
	if (posX2 <= -640)
		posX2 = 1920;
}

void background::setMenu(int destination)
{
	menu = destination;
}

void background::draw(aie::Renderer2D*	m_2dRenderer, aie::Texture * texture, aie::Font * font)
{
	aie::Input* input = aie::Input::getInstance();
	float textWidth = font->getStringWidth(m_menuText);
	float centredPosX = 640 - (textWidth * 0.5f) + 2;
	//drawing the moving background
	if (menu == 1) // main menu
	{
		//black background
		m_2dRenderer->setRenderColour(0, 0, 0, 1.0f);
		m_2dRenderer->drawBox(640, 360, 1280, 720, 0, 1);
		///________________
		strcpy_s(m_menuText, 64, "SPACE GAME");
		///________________
		//text for the main menu
		m_2dRenderer->setRenderColour(1, 1, 1, 1.0f);
		m_2dRenderer->drawText(font, m_menuText, centredPosX, 450);

		//checks if the buttons have been pressed
		play_button->draw(m_2dRenderer);
		play_button->update();
		options_button->draw(m_2dRenderer);
		options_button->update();
		if (play_button->update())
		{
			std::cout << "Play button clicked" << std::endl;
			menu = 2;
		}
		if (options_button->update())
		{
			std::cout << "options button button clicked" << std::endl;
			menu = 3;
		}
	}

	else if (menu == 2) //game 
	{//draws the moving background
		m_2dRenderer->setUVRect(0, 0, 1.0f, 1.0f);
		m_2dRenderer->setRenderColour(1, 1, 1, 1.0f);
		m_2dRenderer->drawSprite(texture, posX, 360, 1300, 720, 0, 100);
		m_2dRenderer->drawSprite(texture, posX2, 360, 1300, 720, 0, 100);
	}

	else if (menu == 3) // the options/how to play menu
	{
		//draws the black background
		m_2dRenderer->setRenderColour(0, 0, 0, 1.0f);
		m_2dRenderer->drawBox(640, 360, 1280, 720, 0, 1);
		//draws text
		m_2dRenderer->setRenderColour(1, 1, 1, 1.0f);
		strcpy_s(m_menuText, 64, "CONTROLS");
		m_2dRenderer->drawText(font, m_menuText, 590, 550);
		strcpy_s(m_menuText, 64, "The arrow keys control movement");
		m_2dRenderer->drawText(font, m_menuText, 430, 500);
		strcpy_s(m_menuText, 64, "The space bar controls shooting");
		m_2dRenderer->drawText(font, m_menuText, 430, 450);
		strcpy_s(m_menuText, 64, "Be warned you will only have 5 lives");
		m_2dRenderer->drawText(font, m_menuText, 400, 350);
		strcpy_s(m_menuText, 64, "Health is located at the bottom middle of the screen");
		m_2dRenderer->drawText(font, m_menuText, 290, 300);
		strcpy_s(m_menuText, 64, "The red circle is your hitbox");
		m_2dRenderer->drawText(font, m_menuText, 440, 250);


		//checks if the button has been clicked
		menu_button->draw(m_2dRenderer);
		menu_button->update();
		if (menu_button->update())
		{
			std::cout << "menu button clicked" << std::endl;
			menu = 1;
		}
	}
	else if (menu == 4)
	{
		//draws the black background
		m_2dRenderer->setRenderColour(0, 0, 0, 1.0f);
		m_2dRenderer->drawBox(640, 360, 1280, 720, 0, 2);

		m_2dRenderer->setRenderColour(1, 1, 1, 1.0f);
		strcpy_s(m_menuText, 64, "You have died");
		m_2dRenderer->drawText(font, m_menuText, centredPosX - 20, 400);
		strcpy_s(m_menuText, 64, "Press ESC to quit");
		m_2dRenderer->drawText(font, m_menuText, centredPosX - 40, 300);
	}

}


int background::getMenu()
{
	return menu;
}