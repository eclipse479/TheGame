#pragma once
#include "Input.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "solidObject.h"
class player :	public solidObject
{
public:
	player();


	~player();


	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D*	m_2dRenderer);

	virtual void shoot(aie::Renderer2D*	m_2dRenderer);

protected:
	aie::Texture* m_shipTexture;

private:
	float positionX = 640;//starting X pos
	float positionY = 360; // starting Y pos
	float playerW = 50; // player width
	float playerH = 50; // player height
	float rotation = -3.14159f / 2; //radians
	float PI = 3.14159f; // value of Pi -> to find angles
	float m_speed;
};
