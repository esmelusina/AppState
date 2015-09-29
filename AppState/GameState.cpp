#include "GameState.h"
#include <random>
#include <iostream>

void GameState::play()
{
	system("cls");
	std::cout << "Guess how many hugs you can handle!" << std::endl << std::endl;
	numberToGuess = rand() % 6;
	guessCount = 3;
}

/*
	A simple guessing game.
*/
STATE GameState::update(/*float dt*/)
{
	int selection;		
	std::cout << "You have " << guessCount << " left" << std::endl;
	guessCount--;

	selection = getNumValid(0,5);

	
	if		(selection < numberToGuess) std::cout << "TOO SMALL!" << std::endl;
	else if (selection > numberToGuess) std::cout << "TOO BIG!" << std::endl;
	else								std::cout << "JUST RIGHT!" << std::endl;

	std::cout << std::endl;

	if (guessCount == 0 || numberToGuess == selection)
	{
		system("pause");
		return MAIN;
	}
	else return GAME;
}
