/***********************************************************
* Author:		Eli Kloft
* Lab Number:	lab3
* Filename:		Lab3.cpp
* Date Created:	4/29/13
* Modifications:5/6/13
*
* Overview:
*	The classic game FreeCell!
*
* Input:
*	0 for random shuffle
*	1 for cards in order
*
* Output:
*	displays the game board and prompts for input
*	displays simple win / lose title and prompt for 
*		playing again or not
************************************************************/
#include "freecell.h"
#include "deck.h"
#include <iostream>
using std::cout;
using std::cin;

#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	FreeCell f1;
	int cheatcode = 0;
	cout << "cheatcode(or 0 for random game): ";
	cin >> cheatcode;
	f1.StartGame(cheatcode);
	system("Pause");
	return 0;
}