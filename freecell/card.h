#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <ostream>
using std::ostream;
using std::cout;
using std::endl;
using std::cin;
const int NUM_RANKS = 13;
const int NUM_SUITS = 4;
//static const char* Suit[NUM_SUITS] = {"Club", "Diamond", "Heart", "Spade"};
const char Suit[ 4 ] = { 0x05, 0x04, 0x03, 0x06 };
static const char * Rank[NUM_RANKS] = {" A", " 2", " 3", " 4", " 5", " 6",
								" 7", " 8", " 9", "10", " J", " Q", " K" };
/************************************************************************
* Class: card
*
* Constructors:	
*	card(int , int)
*		rank and suit initialized to value passed in
	private copy ctor
		to prevent cheating
*
* Mutators:
*	void setvalue(int)
		set a value to a card for a points game
*
* Methods:		
*	int GetRank();  returns ranks
	int GetSuit();  returns suit
	int Getvalue();  returns value
	void Card::Display(); displays suit and rank
*************************************************************************/

class Card
{
	friend bool Equal(const Card & lhs, const Card & rhs);
	
public:
	int GetRank();
	int GetSuit();
	int Getvalue();
	void SetValue(int value);
	~Card();
	Card();
	Card(int suit, int rank, int value = 0);
	Card & operator =(const Card & rhs);
	Card(const Card & in);
	void Display();
	bool isRed();
private:
	int m_suit;
	int m_rank;
	int m_value;
	bool m_isRed;
};


#endif