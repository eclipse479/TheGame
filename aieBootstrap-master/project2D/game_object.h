#pragma once
#include "Renderer2D.h"
namespace aie
{
	class Texture;
	class Renderer2D;
}

class game_object
{
public:
	game_object(aie::Texture* const a_texture);
	~game_object();

	void set_position(float x, float y);
	float get_positionX() const;
	float get_positionY() const;

	void set_rotation(float a_rotation);
	float get_rotation() const;

	void draw(aie::Renderer2D*	a_renderer);
	
private:
	aie::Texture *m_texture = nullptr;
	float m_positionX = 0.0f;
	float m_positionY = 0.0f;
	float m_rotation = 0.0f;
};

