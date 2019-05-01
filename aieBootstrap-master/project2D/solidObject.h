#pragma once
#include "Renderer2D.h"
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include "..\dependencies\glm\glm\ext.hpp"
class solidObject
{
public:
	solidObject();
	~solidObject();
	

	void setObject(float x, float y, float width, float height, float radius);
	float getPositionX();
	float getPositionY();
	float getWidth();
	float getHeight();
	float getRadius();
protected:



	float positionX;
	float positionY;
	float objectWidth;
	float objectHeight;
	float objectRadius;
private:
};


