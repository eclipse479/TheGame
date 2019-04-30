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