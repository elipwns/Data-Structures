#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "doublelinkedlist.h"
#include "card.h"
#include "deck.h"
#include "StackLinked.h"
#include "node.h"
#include "exception.h"
#include "PlayerField.h"
#include "Board.h"
int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	Deck * d1 = new Deck;
	Board b1;
	b1.DealCards(d1);
	b1.Display();

	for(int i = 0; i < 7; i++)
	{
		b1.m_player_field[0].PlaceCard(b1.m_player_field[1].TakeCard());
	}
	b1.Display();

	delete d1;
	return 0;
}