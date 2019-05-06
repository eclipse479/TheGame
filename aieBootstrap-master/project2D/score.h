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
	int getScore();
	int getHighScore();
	void scoreStartup();
	void scoreUpdate(int points);
	
	void writeScore(aie::Renderer2D* renderer);
private:
	aie::Font* m_font;
	char m_buttonText[64];

		int currentScore = 0;
		int highScore = 100000;
		char scoring[50];
	float m_posX;
	float m_posY;

};

