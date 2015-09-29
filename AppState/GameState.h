#pragma once
#include "consts.h"

/*
	A gamestate for a simple guessing game.

	You might want to use something similar!

*/

class GameState
{
	int numberToGuess;
	int guessCount;

public:
	void play();
	STATE update();
};