#include "Board.h"
#include <Windows.h>
/**********************************************************************	
* Purpose: board ctor
*
* Entry:
*
* Exit: makes the playerfield array, homecell array and free cell array
************************************************************************/
Board::Board()
	:m_player_field(Array<PlayerField<Card>>(8)), 
	m_home_cells(Array<HomeCells<Card>>(4)),
	m_free_cells(Array<Card>(4))
{
}
/**********************************************************************	
* Purpose: dtor
*
* Entry:
*
* Exit:
************************************************************************/
Board::~Board()
{
	for (int i(0);i< 8;++i)
		m_player_field[i].~PlayerField();
	m_player_field.~Array();
	m_home_cells.~Array();
	m_free_cells.~Array();
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a board by const ref
*
* Exit: uses op =
************************************************************************/
Board::Board(const Board & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: overloaded op =
*
* Entry: passed a board by const ref
*
* Exit: copies data, returns this
************************************************************************/
Board & Board::operator = (const Board & rhs)
{
	if (this != &rhs)
	{
		m_free_cells = rhs.m_free_cells;
		m_home_cells = rhs.m_home_cells;
		m_player_field = rhs.m_player_field;
	}
	return * this;
}
/**********************************************************************	
* Purpose: deals cards to player field
*
* Entry: passed a deck by pointer
*
* Exit: deals the cards in the deck to the player field
************************************************************************/
void Board::DealCards(Deck * d1)
{
	for(int i = 0; i < 52; i++)
	{
		Card * temp = d1->Draw();
		m_player_field[i % 8].PlaceCard(*temp);
	}
}
/**********************************************************************	
* Purpose: checks if the game has been won
*
* Entry:
*
* Exit: returns true if all home cells are complete
************************************************************************/
bool Board::CheckWin()
{
	if(m_home_cells[0].CheckifComplete())
		if(m_home_cells[1].CheckifComplete())
			if(m_home_cells[2].CheckifComplete())
				if(m_home_cells[3].CheckifComplete())
					return true;
	
	return false;
}
/**********************************************************************	
* Purpose: to display the board
*
* Entry:
*
* Exit: displays free cells, then home cells then all the player area
************************************************************************/
void Board::Display()
{
	system("CLS");
	cout << "  1    2     3     4                     1     2     3     4\n";
	bool done = false;
	bool temp;
	for(int i = 0; i < 4; i++)
	{
		m_free_cells[i].Display();
		cout << " | ";
	}
	cout << "|| Free Cell || ";
	for(int i = 0; i < 4; i++)
	{
		m_home_cells[i].Display();
		cout << " | ";
	}
	cout << "\n\n";
	cout << "  1  2  3  4  5  6  7  8\n";
	for(int i = 0; !done; i++)
	{
		done = true;
		temp = true;
		for(int j = 0; j < 8 ; j++)
		{
			temp = m_player_field[j].Display(i);
			if(!temp)
				done = false;
		}
		cout << "\n";
	}
}

