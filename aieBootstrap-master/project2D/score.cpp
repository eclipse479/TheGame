#include "score.h"
#include <iostream>


score::score()
{
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
}


score::~score()
{
	delete m_font;
}

void score::scoreUpdate(int points)
{
	currentScore += points;

}

int score::getScore()
{
	return currentScore;
}

int score::getHighScore()
{
	return highScore;
}

void score::scoreStartup()
{
	//creates a binary file called "score.dat" if it does not exist and inputs a high score of 100000
	std::fstream fout; // opens a stream for reading
	fout.open("score.dat", std::ios::in | std::ios::out | std::ios::binary);
	if (!fout.good()) // if it does not exist
	{
		fout.open("score.dat", std::ios::out | std::ios::binary); //creates the files
		if (fout.good()) //if the file opens
		{
			//--------------------------------------------- WRITING TO A FILE-------------------------------------------------------
			fout.write((char*)&highScore, sizeof(10)); // write the numbers into the file
			fout.close(); // close the file
		}
	}
}

void score::scoreBoard(aie::Renderer2D* renderer)
{
	//-------------------------------------------------DEFINING THE NUMBERS----------------------------------------------------


	std::fstream fin;
	fin.open("score.dat", std::ios::in | std::ios::binary); // reopens the 'score.dat' file
	if (fin.good())  // if the file opens
	{
		for (int i = 0; i < 1 && !fin.eof() && fin.peek() != EOF; i++) // makes sure the number copied does not go past what is there
		{
			fin.read((char*)&highScore, sizeof(10)); // reads the numbers form the file
		}
	}

	if (currentScore >= highScore) // if the current score is bigger than the high score
	{
		highScore = currentScore;
		std::fstream fout; // opens a stream for reading
		fout.open("score.dat", std::ios::out | std::ios::binary); //creates the files
		if (fout.good()) //if the file opens
		{
			//--------------------------------------------- WRITING TO A FILE-------------------------------------------------------
			fout.write((char*)&currentScore, sizeof(10)); // write the numbers into the file
		}
		fout.close();
	}
	std::cout << currentScore << " thescore\n";
	std::cout << highScore << " highScore\n";

}

void score::writeScore(aie::Renderer2D* renderer)
{
	renderer->setRenderColour(1, 1, 1);
	sprintf_s(scoring, 32, "SCORE: %i", getScore());
	renderer->drawText(m_font, scoring, 500, 720 - 32,90);

	renderer->setRenderColour(1, 1, 1);
	sprintf_s(scoring, 32, "HIGH SCORE: %i", getHighScore());
	renderer->drawText(m_font, scoring, 800, 720 - 32,90);
}