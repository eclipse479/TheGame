#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "game_object.h"
#include "button.h"
#include "background.h"
#include "player.h"


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() { // creates things for the game

	m_2dRenderer = new aie::Renderer2D();

	m_player = new player();
	m_player->setObject(200, 360, 50, 50, 50);

	//m_STexture = new aie::Texture("../bin/textures/ship.png");

	/*ship = new game_object(m_STexture);
	ship->set_position(200, 200);
	ship->set_rotation(1.7f);*/

	m_background = new background();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_button = new button("Play",640,210,150,100,1.0f,0.0f,0.0f);

	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{	
	delete m_player;
	delete m_font;
	delete m_2dRenderer;
	delete m_background;
	delete m_button;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;
	m_player->update(deltaTime);
	// input example
	aie::Input* input = aie::Input::getInstance();

	/*float shipX = ship->get_positionX();
	float shipY = ship->get_positionY();
	float ship_rot = ship->get_rotation();
	float temp_speed = 100.0f;

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		shipX += cos(-ship_rot - 3.14159f * 0.5f) * temp_speed * deltaTime;
		shipY += -sin(-ship_rot - 3.14159f * 0.5f) * temp_speed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		shipX -= cos(-ship_rot - 3.14159f * 0.5f) * temp_speed * deltaTime;
		shipY -= -sin(-ship_rot - 3.14159f * 0.5f) * temp_speed * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		ship_rot += 3.14159f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		ship_rot -= 3.14159f * deltaTime;

	ship->set_position(shipX, shipY);
	ship->set_rotation(ship_rot);*/
	m_background->update(deltaTime);

	m_button->update();
	if (m_button->update()) {	
	//Replace this with whatever the button should do.
		std::cout <<"Button clicked"<<std::endl;
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
	m_background->draw(m_2dRenderer);
	
	//draw the button
	m_button->draw(m_2dRenderer);
	//draw the player
	m_player->draw(m_2dRenderer);

	//ship->draw(m_2dRenderer);
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}