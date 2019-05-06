#pragma once
#include <iostream>
#include <fstream>
#include"Font.h"
#include <cstring>
class score
{
public:
	score(const char* buttonText, float x, float y);
	~score();

	void scoreBoard();
	void scoreUpdate();
private:
	struct scoreStorage
	{
		int score;
		void print()
		{
			std::cout << score << "\n";
		}
	};
	aie::Font* m_font;
	char m_buttonText[64];

	float m_posX;
	float m_posY;

};

