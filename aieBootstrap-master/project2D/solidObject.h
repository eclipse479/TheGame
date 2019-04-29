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
	bool isColliding(solidObject* other);

//	void setPosition(glm::vec2 position) { m_position = position; }
//	void setVelocity(glm::vec2 velocity) { m_velocity = velocity; }
//	void setSize(glm::vec2 size) { m_size = size; }
//	void setColour(glm::vec4 colour) { m_colour = colour; }
//
//
//	glm::vec2 getPosition() { return m_position; }
//	glm::vec2 getVelocity() { return m_velocity; }
//	glm::vec2 getSize() { return m_size; }
//	glm::vec4 getColour() { return m_colour; }


protected:
	glm::vec2 m_position;
	glm::vec2 m_size;
	glm::vec2 m_velocity;
	glm::vec4 m_colour;

	aie::Texture* m_bullet;
private:
	float positionX;
	float positionY;
	float width;
	float height;
	//bool isAlive();
};


