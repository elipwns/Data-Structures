#include "cell.h"
/**********************************************************************	
* Purpose: no arg ctor for cell
*
* Entry: 
*
* Exit: defaults cell to blank cell with coord 0,0
*
************************************************************************/

Cell::Cell()
	:m_x(0), m_y(0), m_isBomb(false), m_number(0), m_covered(true), m_symbol('?')
{
}
/**********************************************************************	
* Purpose: 2 arg ctor for cell
*
* Entry: passed two ints
*
* Exit: sets x,y to the ints passed in and defaults the cell to blank
*
************************************************************************/

Cell::Cell(int x, int y)
	:m_x(x), m_y(y), m_isBomb(false), m_number(0), m_covered(true), m_symbol('?')
{
}
/**********************************************************************	
* Purpose: cell dtor
*
* Entry: 
*
* Exit: 
*
************************************************************************/

Cell::~Cell()
{
}
/**********************************************************************	
* Purpose: cell copy ctor
*
* Entry: passed a const cell by ref
*
* Exit: copies data members
*
************************************************************************/

Cell::Cell(const Cell & copy)
{
	m_x = copy.m_x;
	m_y = copy.m_y;
	m_isBomb = copy.m_isBomb;
	m_covered = copy.m_covered;
	m_number = copy.m_number;
	m_symbol = copy.m_symbol;
}
/**********************************************************************	
* Purpose: overloaded operator =
*
* Entry: passed a const cell by ref
*
* Exit: checks for self assignment then copies the data members
*	returns * this
************************************************************************/

Cell & Cell::operator=(const Cell & rhs)
{
	if(this != &rhs)
	{
		m_x = rhs.m_x;
		m_y = rhs.m_y;
		m_isBomb = rhs.m_isBomb;
		m_number = rhs.m_number;
		m_covered = rhs.m_covered;
		m_symbol = rhs.m_symbol;
	}
	return * this;
}
/**********************************************************************	
* Purpose: overloaded operator <<
*
* Entry: passed an ostream by ref and a const cell by ref
*
* Exit: checks what kind of cell loads stream with the appropriate symbol
*	returns stream
************************************************************************/

ostream & operator<<(ostream & stream, const Cell & cell)
{
	if (cell.m_covered)
		stream << '?';
	else if (cell.m_symbol == 'M')
		stream << cell.m_symbol;
	else if (cell.m_number > 0)
		stream << cell.m_number;
	else if (cell.m_number == 0 && !cell.m_isBomb)
		stream << ' ';
	else
		stream << cell.m_symbol;
	return stream;
}