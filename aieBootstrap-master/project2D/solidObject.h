#pragma once
#include "Input.h"
#include "Texture.h"
#include "Application.h"
#include "Renderer2D.h"
class solidObject
{
public:
	solidObject();
	~solidObject();
	

	void setObject(float x, float y, float width, float height, float radius, aie::Texture* texture, float rotation = 0.0f);
	float getPositionX();
	float getPositionY();
	float getWidth();
	float getHeight();
	float getRadius();

	void draw(aie::Renderer2D*	m_2dRenderer);

protected:
	aie::Texture* textureHold;
	float positionX;
	float positionY;
	float objectWidth;
	float objectHeight;
	float objectRadius;
	float objectRotation = 0;
private:
};


