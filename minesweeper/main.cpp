/***********************************************************
* Author:		Eli Kloft
* Lab Number:	lab1
* Filename:		Lab1.cpp
* Date Created:	4/7/13
* Modifications:4/10/13
*
* Overview:
*	The classic game Minesweeper!
*
* Input:
*	1-3 for Difficulty lv
*	X,Y coords seperated by a space ex ~ X Y
*	1-2 selecting uncover or mark as bomb
*
* Output:
*	displays the game board and prompts for input
*	displays simple win / lose title and prompt for 
*		playing again or not
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "minesweeper.h"
#include "exception.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	Minesweeper * m1 = new Minesweeper;
	m1->Start_Game();
	delete m1;
	return 0;
}