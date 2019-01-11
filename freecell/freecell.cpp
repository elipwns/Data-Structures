#include "freecell.h"

/**********************************************************************	
* Purpose: ctor
*
* Entry:
*
* Exit: makes a new board and deck
************************************************************************/
FreeCell::FreeCell()
{
	m_deck = new Deck;
	m_board = new Board;
}
/**********************************************************************	
* Purpose: dtor
*
* Entry:
*
* Exit: frees memory
************************************************************************/
FreeCell::~FreeCell()
{
	delete m_board;
	delete m_deck;
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a free cell by const ref
*
* Exit: uses op =
************************************************************************/
FreeCell::FreeCell(const FreeCell & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: overloaded op =
*
* Entry: passed a free cell by const ref
*
* Exit: copies data and returns this
************************************************************************/
FreeCell & FreeCell::operator = (const FreeCell &rhs)
{
	if(this != &rhs)
	{
		m_board = rhs.m_board;
		m_deck = rhs.m_deck;
	}
	return * this;
}
/**********************************************************************	
* Purpose: starts the game
*
* Entry: possibly passed an int
*
* Exit: shuffles the deck and starts the game
************************************************************************/
void FreeCell::StartGame(int cheatcode)
{
	bool done = false;
	if(cheatcode)
	{
		m_board->DealCards(m_deck);
		//hardcode a deck. then deal cards as regular
	}
	else
	{
		m_deck->Shuffle();
		m_board->DealCards(m_deck);
	}
	while(!done)
	{
		int ReturnValue = PlayerTurn();
	
		while(!ReturnValue)
		{
			int choice;
			cout << "would you like to restart(1) Quit(2) or continue(3): ";
			cin >> choice;
			if(choice == 1)
				ReturnValue = 2;
			else if (choice == 2)
				ReturnValue = 3;
			else
				ReturnValue = PlayerTurn();
		}
		if(ReturnValue == 1)
		{
			system("CLS");
			cout << "You Win";
			cout << "play again? (y/n): ";
			char temp;
			cin >> temp;
			if(temp == 'y' || temp =='Y')
			{
				delete m_deck;
				m_deck = new Deck;
				m_deck->Shuffle();
				delete m_board;
				m_board = new Board;
				m_board->DealCards(m_deck);
				done = false;
			}
			else
				done = true;
		}
		else if (ReturnValue == 2)
		{
			delete m_deck;
			m_deck = new Deck;
			m_deck->Shuffle();
			delete m_board;
			m_board = new Board;
			m_board->DealCards(m_deck);
			done = false;
		}
		else
		{
			done = true;
		}
	}
}
/**********************************************************************	
* Purpose: displays board then checks if player has won or not
*
* Entry:
*
* Exit: returns 1 if the game has been won, else 0
************************************************************************/
int FreeCell::PlayerTurn()
{
	m_board->Display();
	//players turn
	GetMove();

	if(m_board->CheckWin())
		return 1;
	else
		return 0;
}
/**********************************************************************	
* Purpose: to get a player move
*
* Entry:
*
* Exit: gets player move, then tries to move those cards if possible
************************************************************************/
void FreeCell::GetMove()
{
	char Source, Destination;
	int SourceColumn, DestinationColumn, NumberofCards;
	cout << "\nHow to Submit a Move\n"
		 << "~~~~~~~~~~~~~~~~~~~~~~~~\n"
		 << "F - freecell | H - homecell | P - playercells\n"
		 << "SourceName_ColumnNumber_DestinationName_ColumnNumber_NumberCardsToMove\n"
		 << "Example: P 1 P 2 3\n"
		 << "move 3 cards from playercells, first column, to playercells, second column\n"
		 << "Enter move: ";
	cin >> Source >> SourceColumn >> Destination >> DestinationColumn >> NumberofCards;
	SourceColumn--; DestinationColumn--;
	if(SourceColumn > 7 || DestinationColumn > 7 || NumberofCards > 13 || NumberofCards < 1 || SourceColumn < 0 || DestinationColumn < 0)
		cout << "invalid numbers\n";
	else if(Source == 'F' || Source == 'f')
	{
		if(NumberofCards > 1)
		{
			cout << "Can only move 1 card from FreeCells";
			system("Pause");
		}
		else
		{
			Card blank;
			Card c1 = m_board->m_free_cells[SourceColumn];
			if(Destination == 'p' || Destination == 'P')
			{
				if(c1.isRed() && (m_board->m_player_field[DestinationColumn].Peek()).isRed())
					cout << "Can't move a red card onto another red card\n";
				else if(!c1.isRed() && !(m_board->m_player_field[DestinationColumn].Peek()).isRed())
					cout << "Can't move a black card onto another black card\n";
				else
				{
					if(m_board->m_free_cells[SourceColumn].GetRank() + 1 == m_board->m_player_field[DestinationColumn].Peek().GetRank())
					{
						m_board->m_player_field[DestinationColumn].PlaceCard(c1);
						m_board->m_free_cells[SourceColumn] = blank;
					}
					else
						cout << "Cards need to be placed sequentially\n";
				}
			}
			else if (Destination == 'h' || Destination == 'H')
			{
				if(m_board->m_home_cells[DestinationColumn].Peek().GetSuit() != m_board->m_free_cells[SourceColumn].GetSuit())
				{
					cout << "Suit must be the same for placing cards onto homecells\n";
				}
				else if(m_board->m_home_cells[DestinationColumn].Peek().GetRank() == m_board->m_free_cells[SourceColumn].GetRank() + 1)
				{
					m_board->m_home_cells[DestinationColumn].AddCard(c1);
					m_board->m_free_cells[SourceColumn] = blank;
				}
				else
					cout << "Cards need to be placed sequentially\n";
			}
			else if(Destination == 'f' || Destination == 'F')
			{
				if(m_board->m_free_cells[DestinationColumn].GetRank() > 0)
					cout << "There is already a card in that spot!\n";
				else
				{
					m_board->m_free_cells[DestinationColumn] = c1;
					m_board->m_free_cells[SourceColumn] = blank;
				}
			}
		}
	}
	else if(Source == 'P' || Source == 'p')
	{
		if(Destination == 'p' || Destination == 'P')
		{
			if (NumberofCards == 1)
			{
				if(m_board->m_player_field[DestinationColumn].isEmpty())
				{
					m_board->m_player_field[DestinationColumn].PlaceCard(m_board->m_player_field[SourceColumn].TakeCard());
				}
				else if(m_board->m_player_field[DestinationColumn].Peek().isRed() && m_board->m_player_field[SourceColumn].Peek().isRed())
					cout << "Cant put red card on another red card\n";
				else if(!m_board->m_player_field[DestinationColumn].Peek().isRed() && !m_board->m_player_field[SourceColumn].Peek().isRed())
					cout << "Cant put black card on another black card\n";
				else
				{
					if(m_board->m_player_field[DestinationColumn].Peek().GetRank() == m_board->m_player_field[SourceColumn].Peek().GetRank() + 1)
					{
						m_board->m_player_field[DestinationColumn].PlaceCard(m_board->m_player_field[SourceColumn].TakeCard());
					}
					else
						cout << "Cards need to be placed Sequentially\n";
				}
			}
			else if (NumberofCards <= SuperMove() && NumberofCards <= m_board->m_player_field[SourceColumn].Size())
			{
				bool ordered = true;
				int temp;
				for(int i = 0; i < NumberofCards; i++)
				{
					if(DestinationColumn > 0 && SourceColumn > 0)
					{
						m_board->m_player_field[0].PlaceCard(m_board->m_player_field[SourceColumn].TakeCard());
						temp = 0;
					}
					else if (DestinationColumn != 1 && SourceColumn != 1)
					{
						m_board->m_player_field[1].PlaceCard(m_board->m_player_field[SourceColumn].TakeCard());
						temp = 1;
					}
					else if (DestinationColumn != 2 && SourceColumn != 2)
					{
						m_board->m_player_field[2].PlaceCard(m_board->m_player_field[SourceColumn].TakeCard());
						temp = 2;
					}
					if( i + 1 < NumberofCards)
					{
						if(m_board->m_player_field[temp].Peek().GetRank() + 1 != m_board->m_player_field[SourceColumn].Peek().GetRank())
						{
							ordered = false;
						}
					}
				}
				if(!ordered)
				{
					cout << "Cards need to be in sequential order to move as a stack!\n";
					for(int i = 0; i < NumberofCards; i++)
						m_board->m_player_field[SourceColumn].PlaceCard(m_board->m_player_field[temp].TakeCard());
				}
				else if(m_board->m_player_field[DestinationColumn].isEmpty())
				{
					for(int i = 0; i < NumberofCards; i++)
					{
						m_board->m_player_field[DestinationColumn].PlaceCard(m_board->m_player_field[temp].TakeCard());
					}
				}
				else if(m_board->m_player_field[DestinationColumn].Peek().isRed() && m_board->m_player_field[temp].Peek().isRed())
				{
					cout << "Cant put red card on another red card\n";
					for(int i = 0; i < NumberofCards; i++)
						m_board->m_player_field[SourceColumn].PlaceCard(m_board->m_player_field[temp].TakeCard());
				}
				else if(!m_board->m_player_field[DestinationColumn].Peek().isRed() && !m_board->m_player_field[temp].Peek().isRed())
				{
					cout << "Cant put black card on another black card\n";
					for(int i = 0; i < NumberofCards; i++)
						m_board->m_player_field[SourceColumn].PlaceCard(m_board->m_player_field[temp].TakeCard());
				}
				else if(m_board->m_player_field[DestinationColumn].Peek().GetRank() != m_board->m_player_field[temp].Peek().GetRank() + 1)
				{
					cout << "Cards need to be placed sequentially\n";
					for(int i = 0; i < NumberofCards; i++)
						m_board->m_player_field[SourceColumn].PlaceCard(m_board->m_player_field[temp].TakeCard());
				}
				else 
				{
					for(int i = 0; i < NumberofCards; i++)
					{
						m_board->m_player_field[DestinationColumn].PlaceCard(m_board->m_player_field[temp].TakeCard());
					}
				}
			}
			else
				cout << "Can't Move that many cards!\n";
		}
		else if (Destination == 'h' || Destination == 'H')
		{
			if(NumberofCards > 1)
			{
				cout << "Can only move 1 card to Homecells";
				system("Pause");
			}
			else
			{
				if(m_board->m_home_cells[DestinationColumn].Peek().GetRank() < 0)
					m_board->m_home_cells[DestinationColumn].AddCard(m_board->m_player_field[SourceColumn].TakeCard());
				else if(m_board->m_home_cells[DestinationColumn].Peek().GetRank() + 1 == m_board->m_player_field[SourceColumn].Peek().GetRank())
				{
					if(m_board->m_home_cells[DestinationColumn].Peek().GetSuit() == m_board->m_player_field[SourceColumn].Peek().GetSuit())
					{
						m_board->m_home_cells[DestinationColumn].AddCard(m_board->m_player_field[SourceColumn].TakeCard());
					}
					else
						cout << "Need to be same suit to place on homecell\n";
				}
				else
					cout << "Cards need to be placed sequentially\n";
			}
		}
		else if (Destination == 'f' || Destination == 'F')
		{
			if(NumberofCards > 1)
			{
				cout << "Can only move 1 card to freecells";
				system("Pause");
			}
			else
			{
				if(m_board->m_free_cells[DestinationColumn].GetRank() < 0)
					m_board->m_free_cells[DestinationColumn] = m_board->m_player_field[SourceColumn].TakeCard();
				else
					cout << "There is already a card there!\n";
			}
		}
	}
	else
	{
		cout << "Invalid Move\n";
		system("Pause");
	}
}
/**********************************************************************	
* Purpose: checks max cards that can be moved
*
* Entry:
*
* Exit: returns max moves possible
************************************************************************/
int FreeCell::SuperMove()
{
	int total = 0;
	for(int i = 0; i < 4; i++)
	{
		if(m_board->m_free_cells[i].GetRank() < 0)
			total++;
	}
	int cols = 0;
	for(int i = 0; i < 8; i++)
	{
		if(m_board->m_player_field[i].Peek().GetRank() < 0)
			cols++;
	}
	total++;
	for(int i = 0; i < cols; i++)
	{
		total *= 2;
	}
	return total;
}
