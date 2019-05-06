#include "game_object.h"



game_object::game_object(aie::Texture* const a_texture)
{
	m_texture = a_texture;
}


game_object::~game_object()
{
}


void game_object::set_position(float x, float y)
{
	m_positionX = x;
	m_positionY = y;
}
float game_object::get_positionX() const
{
	return m_positionX;
}
float game_object::get_positionY() const
{
	return m_positionY;
}


void game_object::set_rotation(float a_rotation)
{
	m_rotation = a_rotation;
}
float game_object::get_rotation() const
{
	return m_rotation;
}

void game_object::draw(aie::Renderer2D*	a_renderer)
{
	a_renderer->drawSprite(m_texture, m_positionX, m_positionY, 50, 50, m_rotation, 1);
}

//put this text in the startUp()
//m_STexture = new aie::Texture("../bin/textures/ship.png");
//ship = new game_object(m_STexture);
//ship->set_position(200, 200);
//ship->set_rotation(1.7f);

		//put the below code into the update() of application 2D to get a ship
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

	//put this in the draw()
//ship->draw(m_2dRenderer);

			// this goes in the Application2D header in the protected section
// aie::Texture*	m_STexture;