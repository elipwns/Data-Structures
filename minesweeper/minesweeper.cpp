#include "minesweeper.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
/**********************************************************************	
* Purpose: Minesweeper no arg ctor
*
* Entry: 
*
* Exit: creates a new board
*
************************************************************************/

Minesweeper::Minesweeper()
{
	m_board = new Board();
}
/**********************************************************************	
* Purpose: Minesweeper dtor
*
* Entry: 
*
* Exit: deletes the board
*
************************************************************************/

Minesweeper::~Minesweeper()
{
	delete m_board;
}
/**********************************************************************	
* Purpose: starts the game
*
* Entry: 
*
* Exit: allows user to choose difficulty and sets up the board accordingly
*
************************************************************************/

void Minesweeper::Start_Game()
{
	char choice = 'y';
	int difficulty;
	while(choice == 'y' || choice == 'Y')
	{
		cout << "Difficulty levels" << endl
			 << "level 1 - 10x10 - 10 mines" << endl
			 << "level 2 - 16x16 - 40 mines" << endl
			 << "level 3 - 16x30 - 100 mines" << endl
			 << "Enter level: ";
		cin >> difficulty;
		while (difficulty <= 0 || difficulty >= 4)
		{
			cout << "pick a number between 1 - 3" << endl;
			cin >> difficulty;
		}

		switch (difficulty)
		{
		case 1:
			m_board->setRow(10);
			m_board->setCol(10);
			m_board->setMines(10);
			break;
		case 2:
			m_board->setRow(16);
			m_board->setCol(16);
			m_board->setMines(40);
			break;
		case 3:
			m_board->setRow(16);
			m_board->setCol(30);
			m_board->setMines(100);
			break;
		default:
			cout << "Next time pick a number between 1 - 3\n";
			return;
		}
		m_board->Lay_Mines();
	
		cout << "You win\n\n" << "play again? y/n : ";
		cin >> choice;
		delete m_board;
		m_board = new Board();
		cout << system("cls");
	}

}

