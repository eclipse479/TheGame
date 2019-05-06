#pragma once
#include <iostream>
#include <fstream>
#include"Font.h"
#include <cstring>
#include"Renderer2D.h"
class score
{
public:
	score();
	~score();

	void scoreBoard(aie::Renderer2D* renderer);

	void scoreStartup();
	void scoreUpdate(int points);
private:
	aie::Font* m_font;
	char m_buttonText[64];

		int currentScore = 0;
		int highScore = 100000;
		char currentScoreText[64];
		char highScoreText[64];

	float m_posX;
	float m_posY;

};

