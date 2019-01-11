/************************************************************************
* Class: Board
*
* Purpose: This class contains all the important functions dealing with
*	the playing field, including setting the bombs and numbers, and
*	dealing with the player's turn.
*
* Manager functions:	
* 	Board ( )
* 		sets done to false which is the end game flag
*	Board (const Board & copy)
*		copy constructor
*	operator = (const Board & copy)
*		overloaded operator =
*	~Board()
*		destructor
*	Getter and setter for Row, Mines, and Column
*
* Methods:		
*	void DisplayBoard()
*		2 for loops that print out the board row by row
*	void Lay_Mines()
*		finds random coords to place bombs at
*	void Player_turn()
*		loops while not end game, gets user input
*	void Set_Numbers()
*		sets the cell number by checking its 8 neighbors
*	void Uncover(int xStart, int yStart)
*		shows blank or number or bomb when selecting a cell
*	void Uncover_Loop(int xStart, int yStart, LinkedList * start)
*		loops through blank adjacent cells uncovering them
*	void Check_Win()
*		checks to see if the player has won yet
*************************************************************************/

#include "cell.h"
#include "array2d.h"
#include "Node.h"

#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
	Board();
	~Board();
	Board(const Board & copy);
	Board & operator=(const Board & rhs);

	void setRow(int rows);
	int getRow();
	int getCol();
	int getMines();
	void setCol(int cols);
	void setMines(int mines);

	void DisplayBoard();
	void Lay_Mines();
	void Player_turn();
	void Set_Numbers();
	void Uncover(int xStart, int yStart);
	void Uncover_Loop(int xStart, int yStart, LinkedList * start);
	void Check_Win();

private:
	int m_mines;
	bool m_done;
	Array2d<Cell> m_field;
};

#endif