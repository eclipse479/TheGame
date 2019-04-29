#pragma once
#include "Renderer2D.h"
#include "Texture.h"
#include "Input.h"
class background
{
public:
	background();
	~background();
	virtual void update(float deltaTime);

	virtual void draw(aie::Renderer2D*	m_2dRenderer);



protected:

	aie::Texture* m_background;

private:

	float posX = 640;
	float posX2 = 1920;
};

