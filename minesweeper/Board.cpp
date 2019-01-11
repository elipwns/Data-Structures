#include "board.h"
#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <stdlib.h>
#include <time.h>
/**********************************************************************	
* Purpose: Board no arg Ctor
*
* Entry: 
*
* Exit: defaults the done flag to false, mines to 0
*
************************************************************************/

Board::Board()
	:m_done(false), m_mines(0)
{
}
/**********************************************************************	
* Purpose: board dtor
*
* Entry: 
*
* Exit: 
*
************************************************************************/

Board::~Board()
{
}
/**********************************************************************	
* Purpose: board copy ctor
*
* Entry: passed a const board by ref
*
* Exit: copys the data memebers
*
************************************************************************/

Board::Board(const Board & copy)
{
	m_mines = copy.m_mines;
	m_done = copy.m_done;
	m_field = copy.m_field;
}
/**********************************************************************	
* Purpose: overloaded op =
*
* Entry: passed a const board by refrence
*
* Exit: if its not self assignment then copy data over
*
************************************************************************/

Board & Board::operator=(const Board & rhs)
{
	if (this != &rhs)
	{
		m_mines = rhs.m_mines;
		m_field = rhs.m_field;
		m_done = rhs.m_done;
	}
	return * this;
}
/**********************************************************************	
* Purpose: to clear the screen then display the board with coords shown
*
* Entry: the board should be setup with X,Y 
*
* Exit: couts text that looks like a playing field
*
************************************************************************/

void Board::DisplayBoard()
{
	system("cls");
	cout << "   ";
	for(int k = 0; k < m_field.getColumn(); k++)
	{
		if (k > 9)
			cout << k;
		else
			cout << k << " ";
	}
	cout << endl;
	cout << "  ";
	for(int k = 0; k < m_field.getColumn(); k++)
		cout << "__";
	cout << endl;

	for (int i = 0; i < m_field.getRow(); i++)
	{
		if ( i < 10)
			cout << i << " |";
		else
			cout << i << "|";

		for(int j = 0; j < m_field.getColumn(); j++)
			cout << m_field[i][j] << " ";
		cout << endl;
	}
}
/**********************************************************************	
* Purpose: setter for row
*
* Entry: passed an int
*
* Exit: passes the int to the setter for array2d
*
************************************************************************/

void Board::setRow(int rows)
{
	m_field.setRow(rows);
}
/**********************************************************************	
* Purpose: getter for row
*
* Entry: 
*
* Exit: returns the int returned by the getter for array2d
*
************************************************************************/

int Board::getRow()
{
	return m_field.getRow();
}
/**********************************************************************	
* Purpose: getter for col
*
* Entry: 
*
* Exit: returns the int returned by the getter for array2d
*
************************************************************************/

int Board::getCol()
{
	return m_field.getColumn();
}
/**********************************************************************	
* Purpose: getter for mines
*
* Entry: 
*
* Exit: returns m_mines
*
************************************************************************/

int Board::getMines()
{
	return m_mines;
}
/**********************************************************************	
* Purpose: setter for columns
*
* Entry: passed an int
*
* Exit: passes the int to the setter for array2d
*
************************************************************************/

void Board::setCol(int cols)
{
	m_field.setColumn(cols);
}
/**********************************************************************	
* Purpose: setter for mines
*
* Entry: passed an int
*
* Exit: sets mines to the int
*
************************************************************************/

void Board::setMines(int mines)
{
	m_mines = mines;
}
/**********************************************************************	
* Purpose: randomly lays the mines
*
* Entry: 
*
* Exit: creates 2 random numbers and sets a mine at that coord
*	then calls set numbers to place numbers in relevant cells
*	then calls players turn
*
************************************************************************/

void Board::Lay_Mines()
{
	srand (time(NULL));
	int randomX, randomY;
	for(int i = m_mines; i > 0; i--)
	{
		randomY = rand() % getRow();
		randomX = rand() % getCol();
		if (m_field[randomY][randomX].m_isBomb)
			i++;
		else
		{
			m_field[randomY][randomX].m_isBomb = true;
			m_field[randomY][randomX].m_symbol = 'X';
		}
	}
	Set_Numbers();
	Player_turn();
}
/**********************************************************************	
* Purpose: sets the numbers
*
* Entry: assumes bombs already been placed
*
* Exit: checks each cells 8 nieghbors and adds one to a counter if bomb
*
************************************************************************/

void Board::Set_Numbers()
{
	int bombs_nearby = 0;
	for(int i = 0; i < m_field.getRow(); i++)
	{
		for(int j = 0; j < m_field.getColumn(); j++)
		{
			if (!m_field[i][j].m_isBomb)
			{
				if(i-1 >= 0)
				{
					if(m_field[i - 1][j].m_isBomb)
						bombs_nearby++;

					if(j-1 >= 0)
						if(m_field[i-1][j - 1].m_isBomb)
							bombs_nearby++;

					if(j+1 < m_field.getColumn())
						if(m_field[i-1][j + 1].m_isBomb)
							bombs_nearby++;
				}

				if(i+1 < m_field.getRow())
				{
					if(m_field[i + 1][j].m_isBomb)
						bombs_nearby++;
					if(j-1 >= 0)
						if(m_field[i + 1][j-1].m_isBomb)
							bombs_nearby++;
					if(j+1 < m_field.getColumn())
						if(m_field[i + 1][j+1].m_isBomb)
							bombs_nearby++;
				}

				if(j-1 >= 0)
					if(m_field[i][j - 1].m_isBomb)
						bombs_nearby++;

				if(j+1 < m_field.getColumn())
					if(m_field[i][j + 1].m_isBomb)
						bombs_nearby++;

				m_field[i][j].m_number = bombs_nearby;
				bombs_nearby = 0;
			}
		}
	}
}
/**********************************************************************	
* Purpose: deals with user input for coord and choices dealing with that
*	coord
*
* Entry: needs a board with bombs and numbers built
*
* Exit: asks user for a square and then asks if they want to toggle the 
*	flag or uncover it
*
************************************************************************/

void Board::Player_turn()
{
	while(!m_done)
	{
		Check_Win();
		DisplayBoard();
		int x, y, choice = 0;

		cout << "Enter coord (Ex ~ 2 3) : ";
		cin >> x >> y;
		while (x < 0 || x > m_field.getColumn() || y < 0 ||
			y > m_field.getRow() || 
			(!m_field[y][x].m_covered && m_field[y][x].m_symbol != 'M'))
		{
			cout << "Enter coord (Ex ~ 2 3) : ";
			cin >> x >> y;
		}

		cout << "1) Uncover\n2) Mark for possible bomb\n";
		cin >> choice;
		while(choice > 2 || choice < 1)
		{
			cout << "1) Uncover\n2) Mark for possible bomb\n";
			cin >> choice;
		}
		
		if(choice == 1)
			Uncover(x, y);
		else if (choice == 2)
		{
			m_field[y][x].m_covered = false;
			if(m_field[y][x].m_symbol == 'M')
			{
				if(m_field[y][x].m_isBomb)
					m_field[y][x].m_symbol = 'X';
				else
					m_field[y][x].m_symbol = ' ';
				m_field[y][x].m_covered = true;
			}
			else
				m_field[y][x].m_symbol = 'M';
		}
	}
}
/**********************************************************************	
* Purpose: the uncover function
*
* Entry: passed an X,Y coord to uncover
*
* Exit: checks if bomb first, you lose
*		then checks if its a number, just display it
*		if its blank start up the uncover loop
*
************************************************************************/

void Board::Uncover(int xStart, int yStart)
{
	if (m_field[yStart][xStart].m_isBomb)
	{
		m_field[yStart][xStart].m_covered = false;
		DisplayBoard();
		cout << "you lose\n";
		m_done = true;
	}
	else if (m_field[yStart][xStart].m_number)
	{
		m_field[yStart][xStart].m_covered = false;
	}
	else
	{
		LinkedList start(xStart, yStart);
		Uncover_Loop(xStart, yStart, &start);
		while(start.m_head->GetNext() != nullptr)
		{
			start.Next();
			Uncover_Loop(start.GetX(), start.GetY(), &start);
		}
	}
}
/**********************************************************************	
* Purpose: used to uncover cells and add them to a que to be checked
*
* Entry: is passed the X,Y coord to start at and a pointer to the linked list
*
* Exit: checks the 4 diagnals for a number to uncover and checks the 4
*	sides for a blank spot to add to the que and to uncover
*
************************************************************************/

void Board::Uncover_Loop(int xStart, int yStart, LinkedList * start)
{
	m_field[yStart][xStart].m_covered = false;
	
	if(yStart - 1 >= 0)
	{
		if(!m_field[yStart - 1][xStart].m_isBomb)
			if(m_field[yStart - 1][xStart].m_covered)
				if(m_field[yStart - 1][xStart].m_symbol != 'M')
					if(!m_field[yStart - 1][xStart].m_number)
					{
						m_field[yStart - 1][xStart].m_covered = false;
						start->Add(xStart, yStart - 1);
					}
					else
						m_field[yStart - 1][xStart].m_covered = false;

		if (xStart - 1 >= 0)
			if(!m_field[yStart - 1][xStart - 1].m_isBomb)
				if(m_field[yStart - 1][xStart - 1].m_covered)
					if(m_field[yStart - 1][xStart - 1].m_symbol != 'M')
						if(!m_field[yStart - 1][xStart - 1].m_number)
						{
							m_field[yStart - 1][xStart - 1].m_covered = false;
							start->Add(xStart - 1, yStart - 1);
						}
						else
							m_field[yStart - 1][xStart - 1].m_covered = false;

		if (xStart + 1 < m_field.getColumn())
			if(!m_field[yStart - 1][xStart + 1].m_isBomb)
				if(m_field[yStart - 1][xStart + 1].m_covered)
					if(m_field[yStart - 1][xStart + 1].m_symbol != 'M')
						if(!m_field[yStart - 1][xStart + 1].m_number)
						{
							m_field[yStart - 1][xStart + 1].m_covered = false;
							start->Add(xStart + 1, yStart - 1);
						}
						else
							m_field[yStart - 1][xStart + 1].m_covered = false;
	}

	if(yStart + 1 < m_field.getRow())
	{
		if(!m_field[yStart + 1][xStart].m_isBomb)
			if(m_field[yStart + 1][xStart].m_covered)
				if(m_field[yStart + 1][xStart].m_symbol != 'M')
					if(!m_field[yStart + 1][xStart].m_number)
					{
						m_field[yStart + 1][xStart].m_covered = false;
						start->Add(xStart, yStart + 1);
					}
					else
						m_field[yStart + 1][xStart].m_covered = false;

		if (xStart - 1 >= 0)
			if(!m_field[yStart + 1][xStart - 1].m_isBomb)
				if(m_field[yStart + 1][xStart - 1].m_covered)
					if(m_field[yStart + 1][xStart - 1].m_symbol != 'M')
						if(!m_field[yStart + 1][xStart - 1].m_number)
						{
							m_field[yStart + 1][xStart - 1].m_covered = false;
							start->Add(xStart - 1, yStart + 1);
						}
						else
							m_field[yStart + 1][xStart - 1].m_covered = false;

		if(xStart + 1 < m_field.getColumn())
			if(!m_field[yStart + 1][xStart + 1].m_isBomb)
				if(m_field[yStart + 1][xStart + 1].m_covered)
					if(m_field[yStart + 1][xStart + 1].m_symbol != 'M')
						if(!m_field[yStart + 1][xStart + 1].m_number)
						{
							m_field[yStart + 1][xStart + 1].m_covered = false;
							start->Add(xStart + 1, yStart + 1);
						}
						else
							m_field[yStart + 1][xStart + 1].m_covered = false;
	}
		
	if(xStart-1 >= 0)
		if(!m_field[yStart][xStart - 1].m_isBomb)
			if(m_field[yStart][xStart - 1].m_covered)
				if(m_field[yStart][xStart - 1].m_symbol != 'M')
					if(!m_field[yStart][xStart - 1].m_number)	
					{
						m_field[yStart][xStart - 1].m_covered = false;
						start->Add(xStart - 1, yStart);
					}
					else
						m_field[yStart][xStart - 1].m_covered = false;

	if(xStart+1 < m_field.getColumn())
		if(!m_field[yStart][xStart + 1].m_isBomb)
			if(m_field[yStart][xStart + 1].m_covered)
				if(m_field[yStart][xStart + 1].m_symbol != 'M')
					if(!m_field[yStart][xStart + 1].m_number)
					{
						m_field[yStart][xStart + 1].m_covered = false;
						start->Add(xStart + 1, yStart);
					}
					else
						m_field[yStart][xStart + 1].m_covered = false;
	DisplayBoard();
}
/**********************************************************************	
* Purpose: this function checks to see if the player has won
*
* Entry: 
*
* Exit: sets done to true and then checks every cell until it finds
*	a cell that fails the check, and then updates the done to false
*
************************************************************************/

void Board::Check_Win()
{
	m_done = true;
	for (int i = 0; i < m_field.getRow() && m_done; i++)
		for (int j = 0; j < m_field.getColumn() && m_done; j++)
			if(m_field[i][j].m_covered && !m_field[i][j].m_isBomb)
				m_done = false;
}