/************************************************************************
* Class: Board
*
* Purpose: to hold the 3 seperate areas of the game
*
* Manager functions:	
* 	Board() - no arg ctor
*	~Board() - dotr
*	Board(const Board &) - copy ctor
*	Board & operator = (const Board &) - overloaded op =
*
* Methods:		
*	void DealCards(Deck *) - deal the cards to play area
*	bool CheckWin() - check if the home cells are full
*	void Display() - display the 3 areas
*************************************************************************/
#include "array.h"
#include "homecells.h"
#include "PlayerField.h"
#include "deck.h"
#ifndef BOARD_H
#define BOARD_H

class Board
{
	friend int main();
	friend class FreeCell;
public:
	Board();
	~Board();
	Board(const Board &);
	Board & operator = (const Board &);
	void DealCards(Deck *);
	bool CheckWin();
	void Display();
private:
	Array<PlayerField<Card>> m_player_field;
	Array<HomeCells<Card>> m_home_cells;
	Array<Card> m_free_cells;
};


#endif