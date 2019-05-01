#pragma once
#include <iostream>
#include <fstream>
class score
{
public:
	score();
	~score();

	void scoreBoard();
	void scoreUpdate();
private:
	struct Scores
	{
		int score;
		void print()
		{
			std::cout << score << "\n";
		}
	};
};

