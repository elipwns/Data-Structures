/************************************************************************
* Class: Minesweeper
*
* Purpose: This class creates a dynamic one-dimensional array that can be 
* started at any base. 
*
* Manager functions:	
* 	Minesweeper ( )
* 		creates a new board to play with 	
*	Minesweeper (const Minesweeper & copy)
*		copy constructor
*	operator = (const Minesweeper & copy)
*		overloaded operator =
*	~Minesweeper()
*		destructor
*
* Methods:		
*	void Start_Game()
*		starts the game
*************************************************************************/

#include "array2d.h"
#include "cell.h"
#include "board.h"

#ifndef MINESWEEPER_H
#define MINESWEEPER_H

class Minesweeper
{
public:
	Minesweeper();
	~Minesweeper();
	Minesweeper(const Minesweeper & copy);
	Minesweeper & operator=(const Minesweeper & rhs);

	void Start_Game();

private:
	Board * m_board;
};



#endif