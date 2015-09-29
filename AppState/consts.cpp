#include "consts.h"
#include <iostream>

// Simple selection menu with some security.
STATE mainMenu()
{
	system("cls");
	std::cout << "Welcome to the main menu!" << std::endl;
	std::cout << "1: Start new game" << std::endl;
	std::cout << "2: Splash Screen"  << std::endl;
	std::cout << "3: Exit Game"		 << std::endl;
		
	switch (getNumValid(1, 3))
	{
	case 1: return PLAY; //return will break the state.
	case 2: return INIT;
	case 3: return EXIT;
	}		
}

// Presents a welcome screen
void splash()
{
	system("cls");
	std::cout << "Welcome to this awesome game!" << std::endl;
	std::cout << "This is a splash or intro state" << std::endl;
	std::cout << "Just a place to show your title/about information" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "####   # #   #  ###    #  # #   #  ####   ###  " << std::endl;
	std::cout << " #  #  # ##  # #   #   #  # #   # #      #     " << std::endl;
	std::cout << " #   # # # # # #   #   #### #   # #  ###  ###  " << std::endl;
	std::cout << " #  #  # #  ## #   #   #  # #   # #   ##     # " << std::endl;
	std::cout << "####   # #   #  ###    #  #  ###   ### #  ###  " << std::endl;
	std::cout << std::endl;
	std::cout << "Esmeralda Salamone, esmes@aie.edu.au, 9/28/2015" << std::endl;
	system("pause");
	system("cls");
}

// presents a farewell screen
void byebye()
{
	system("cls");
	std::cout << "####   # #   #  ###    ###  #   # #####" << std::endl;
	std::cout << " #  #  # ##  # #   #   #  # #   # #    " << std::endl;
	std::cout << " #   # # # # # #   #   ####  # #  ###  " << std::endl;
	std::cout << " #  #  # #  ## #   #   #  #   #   #    " << std::endl;
	std::cout << "####   # #   #  ###    ###    #   #####" << std::endl;
	system("pause");
}


/*
	This useful little guy will produce a prompt, requesting a number.
	It will validate that it is indeed a number and that it is within
	a particular range. A procedure like this is great for getting
	rudimentary input from the user.

	This function WILL cause the application to hang, so if there
	is real-time rendering going on, it will halt.
*/
int getNumValid(int min, int max)
{
	int select;	
	
	do
	{		
		std::cout << "Enter a valid number (" << min << "-" << max << "): ";
		std::cin >> select;

		if (std::cin.fail() || select < min || select > max)
		{
			std::cin.clear();			//clears the input buffer
			std::cin.ignore(80,'\n');	//resets the input buffer
			std::cout << "Invalid entry." << std::endl;
		}
		else break; //stop looping if the input was valid
	} while (true);

	return select;
}