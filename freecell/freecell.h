/************************************************************************
* Class: freecell
*
* Purpose: the main game, gets user input for move
*
* Manager functions:	
*	FreeCell() - no arg ctor
*	~FreeCell() - dtor
*	FreeCell(const FreeCell &) - copy ctor
*	FreeCell & operator = (const FreeCell &) - overloaded op =
*
* Methods:		
*	void StartGame(int cheatcode = 0) - starts the game, optional cheatcode
*	int PlayerTurn() - clears the screen, displays the board, then gets move
*	void GetMove() - gets a move and does all error checking
*	int SuperMove() - checks number of max moves
*************************************************************************/
#include "Board.h"
#include "deck.h"
#ifndef FREECELL_H
#define FREECELL_H

class FreeCell
{
public:
	FreeCell();
	~FreeCell();
	FreeCell(const FreeCell &);
	FreeCell & operator = (const FreeCell &);

	void StartGame(int cheatcode = 0);
	int PlayerTurn();
	void GetMove();
	int SuperMove();
private:
	Board * m_board;
	Deck * m_deck;
};


#endif