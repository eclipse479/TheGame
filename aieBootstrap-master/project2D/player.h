#pragma once
#include "Application.h"
#include "Input.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "solidObject.h"
#include "projectile.h"
class player :	public solidObject
{
public:
	player();


	~player();


	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* m_2dRenderer);

	void setshootingTimer(int timer);
	int shootingTimer();
	bool isShooting();
	void setShooting(bool setshooting);
protected:
	aie::Texture* m_shipTexture;
	aie::Texture* m_playerBullet;
	aie::Renderer2D*	m_2dRenderer;
private:
	float rotation = -3.14159f / 2; //radians
	float PI = 3.14159f; // value of Pi -> to find angles
	float m_speed;
	int shooting_timer;
	bool shooting = false;
};

