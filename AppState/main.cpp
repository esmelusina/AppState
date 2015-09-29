
/*****************
This is a very straightforward application state management system
as an introduction to menuing systems. There are many ways to
solve this problem, but the solution presented here is
quite simple and accessible.

The main idea is to have a switch drive which object gets
updated each time the game loops. This may be a state-less
object, like a splash screen or a simple menu, or it could be
something that we expect to have behavior over multiple loops,
such as a game state. Early on, only the game state would /really/
need to be implemented as an object- but things get progressively
more complex the more information you want available throughout
the entire application.

You may use this as a starting point to implement your own applications.
If you develop an application state that needs data, you should create
 a class, if it doesn't need data, a function will suffice.

Esmeralda Salamone, esmes@aie.edu.au, 9/28/2015

*****************/

#include "consts.h"
#include "GameState.h"


#include <malloc.h>
#include <iostream>

int main()
{
	GameState g;
	STATE current = INIT;	// The start state
	
	while (true)
	{
		switch (current)
		{
		case INIT: splash();					// automatically moves to main menu, so it doesn't break!
		case MAIN: current = mainMenu(); break; // mainMenu returns which state we should move to.
		case PLAY: g.play();					// resets data to start a new game, doesn't need to break!
		case GAME: current = g.update(); break; // Update continuously until we return to main.
		case EXIT: byebye(); return 0;			// return breaks the while loop.
		}
	}
}
