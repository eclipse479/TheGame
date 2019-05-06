#include "score.h"
#include <iostream>


score::score()
{

}


score::~score()
{
}

void score::scoreUpdate(int points)
{
	currentScore += points;

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


	//strcpy_s(currentScoreText, 64, currentScore);
	/*renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	renderer->drawText(m_font, currentScoreText, 200, 600);

	renderer->drawText(m_font, highScoreText, 500, 600);*/
}