#include "solidObject.h"
#include "Texture.h"
#include "..\dependencies\glm\glm\ext.hpp"



solidObject::solidObject()
{

}


solidObject::~solidObject()
{
}

//bool entity::isAlive()
//{
//
//}



bool solidObject::isColliding(solidObject* other)
{
	return glm::distance(other->m_position, m_position);
}