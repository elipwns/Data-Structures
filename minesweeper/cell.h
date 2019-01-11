/************************************************************************
* Class: Cell
*
* Purpose: To hold the status of each indidual x,y coord
*
* Manager functions:	
* 	Cell ( )
* 		defaults x,y to 0,0 and is considered a blank square	
*	Cell (int x, int y)
*		sets cell to a particular x,y coord and defaults to a blank square
*	Cell (const Cell & copy)
*		copy constructor
*	operator = (const Cell & copy)
*		overloaded operator =
*	~Cell()
*		destructor
*
* Methods:		
*	overloaded << operator to easily cout a specific cell with its
*		appropriate symbol
*************************************************************************/
#include <iostream>
using std::ostream;

#ifndef CELL_H
#define CELL_H

class Cell
{
	friend class Board;
public:
	friend ostream & operator<<(ostream & stream, const Cell & cell);

	Cell();
	Cell(int x, int y);
	~Cell();
	Cell(const Cell & copy);
	Cell & operator=(const Cell & rhs);
private:
	int m_x;
	int m_y;
	bool m_isBomb;
	int m_number;
	bool m_covered;
	char m_symbol;
};


#endif