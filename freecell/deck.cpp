#include "deck.h"
/**************************************************************
*	  Purpose: instantiates the deck of cards
*                 
*         Entry:  its a ctor
*
*          Exit:  creates deck and exits
****************************************************************/

Deck::Deck()
	:beenDealt (0)
	{
		int temp = 0;
		for ( int rank = NUM_RANKS - 1; rank >= 0; rank--)
		{
			for ( int suit = NUM_SUITS - 1; suit >= 0; suit--)
			{
				deck [temp++] = new Card(suit , rank);
			}
		}
		AssignValue();
	}
/**************************************************************
*	  Purpose: dtor for deck, frees up memory
*                 
****************************************************************/

Deck::~Deck()
	{
		if(deck[0]->GetSuit() >= 0)
			for (int i = 0; i < STANDARD_DECK; i++)
			{
				delete deck[i];
			}
	}
/**************************************************************
*	  Purpose: to draw a card
*                 
*         Entry: called when someone draws a card
*
*          Exit:  returns a pointer to a card and increases beenDealt
****************************************************************/

Card * Deck::Draw ()
	{
		return deck[beenDealt++];
	}
/**************************************************************
*	  Purpose:  shuffles the deck
*                 
*         Entry:  called when someones shuffles deck
*
*          Exit:  picks random cards out, replaces them with end card,
				  puts random card into temp array, then when deck is empty,
				  copy the cards back over.
****************************************************************/

void Deck::Shuffle()
	{
		beenDealt = 0;
		srand ( time(NULL) );
		Card * tempdeck [52];
		for (int i = 0; i < 52; i++)
		{
			int RandomNum = rand() % (STANDARD_DECK - i);
			Card * tempcard = deck[RandomNum];
			deck[RandomNum] = deck[STANDARD_DECK - 1 - i];
			tempdeck[i] = tempcard;
		}

		for (int i = 0; i < 52; i++)
		{
			deck[i] = tempdeck[i];
		}

	}
void Deck::AssignValue()
{
	int rank;
	for ( int i = 0; i < 52; i++)
	{
		rank = deck[i]->GetRank();
		if ( rank < 9)
			deck[i]->SetValue(rank + 1);
		else
			deck[i]->SetValue(10);
	}
}
