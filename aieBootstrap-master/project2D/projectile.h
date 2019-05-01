#pragma once
#include "solidObject.h"
class projectile :
	public solidObject
{
public:
	projectile();
	~projectile();

private:
	int bulletType;

};

