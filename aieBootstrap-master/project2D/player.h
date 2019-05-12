#pragma once
#include "solidObject.h"
#include "projectile.h"
class player : public solidObject
{
public:
	player(float posX, float posY, float width, float height, float radius, aie::Texture* texture, float rotation);


	~player();


	virtual void player_update(float deltaTime);

	void setshootingTimer(int timer);
	int shootingTimer();
	bool isShooting();
	void setShooting(bool setshooting);
	void addHealth(int add);
	int getHealth();
protected:
	aie::Renderer2D*	m_2dRenderer;
private:
	float rotation = -3.14159f / 2; //radians
	float PI = 3.14159f; // value of Pi -> to find angles
	float m_speed;
	int shooting_timer;
	bool shooting = false;
	int health = 5;
};

