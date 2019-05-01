#include "score.h"
#include <iostream>


score::score()
{
}


score::~score()
{
}

void score::scoreUpdate()
{

}

void score::scoreBoard() 
{
	Scores thescore; //create -> user score
	thescore.score = 0; //assign
	Scores highScore;//create
	highScore.score = 100656;//assign
	Scores holdScore; // holds the numbers + create
	//-------------------------------------------------DEFINING THE NUMBERS----------------------------------------------------

	std::fstream fout; // opens a stream for reading
	fout.open("score.dat", std::ios::in | std::ios::out | std::ios::binary);
	if (fout.good()) // if it open close it
	{
		fout.close(); // close the file
	}
	else  // if it doesn't open create it and put in highscore
	{
		fout.open("score.dat", std::ios::out | std::ios::binary); //creates the files
		if (fout.good()) //if the file opens
		{
			//--------------------------------------------- WRITING TO A FILE-------------------------------------------------------
			fout.write((char*)&highScore, sizeof(Scores)); // write the numbers into the file
			fout.close(); // close the file
		}
	}


	std::fstream fin;
	fin.open("score.dat", std::ios::in | std::ios::binary); // reopens the 'score.dat' file
	if (fin.good())  // if the file opens
	{
		for (int i = 0; i < 1 && !fin.eof() && fin.peek() != EOF; i++) // makes sure the number copied does not go past what is there
		{
			fin.read((char*)&holdScore, sizeof(Scores)); // reads the numbers form the file
		}
	}

	if (thescore.score >= holdScore.score) // if the current score is bigger than the high score
	{
		highScore.score = thescore.score;
		fout.open("score.dat", std::ios::out | std::ios::binary); //creates the files
		if (fout.good()) //if the file opens
		{
			//--------------------------------------------- WRITING TO A FILE-------------------------------------------------------
			fout.write((char*)&thescore, sizeof(Scores)); // write the numbers into the file
		}
		for (int i = 0; i < 1 && !fin.eof() && fin.peek() != EOF; i++) // makes sure the number copied does not go past what is there
		{
			//-------------------------------------------WRITING THE NUMBERS FROM THE FILE---------------------------------------------
			fin.read((char*)&holdScore, sizeof(Scores)); // reads the numbers form the file
		}
		fout.close();//close the file
	}
	std::cout << thescore.score << " thescore\n";
	std::cout << holdScore.score << " holdScore\n";
	std::cout << highScore.score << " highScore\n";
}