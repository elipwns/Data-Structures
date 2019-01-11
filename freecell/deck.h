#ifndef DECK_H
#define DECK_H
#include "card.h"
#include "cstdlib"
using std::rand;
using std::srand;
#include "time.h"

const int STANDARD_DECK = 52;
/************************************************************************
* Class: deck
*
* Constructors:	
*	deck()
*		this initializes the deck of cards
* Mutators:
*	void shuffle()
		shuffles the deck
*
* Methods:		
*	card * draw()
		returns a pointer to a card
*************************************************************************/

class Deck
{
public:
	
	Deck();
	~Deck();
	Card * Draw ();
	void Shuffle();
	
private:
	void AssignValue();
	Card * deck[STANDARD_DECK];
	int beenDealt;
};

#endif