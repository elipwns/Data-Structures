#include "card.h"
#include <Windows.h>
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
/**************************************************************
*	  Purpose:  getter for rank
****************************************************************/

int Card::GetRank()
{
	return m_rank;
}
/**************************************************************
*	  Purpose: getter for suit
****************************************************************/

int Card::GetSuit()
{
	return m_suit;
}
/**************************************************************
*	  Purpose: getter for value
****************************************************************/

int Card::Getvalue()
{
	return m_value;
}
/**************************************************************
*	  Purpose:  setter for vlaue
****************************************************************/

void Card::SetValue(int value)
{
	m_value = value;
}
/**************************************************************
*	  Purpose:  displays the rank and suit
****************************************************************/

void Card::Display()
{
	if(m_rank >= 0)
	{
		if(m_isRed)
			SetConsoleTextAttribute(console, 252);
		else
			SetConsoleTextAttribute(console, 240);
		int rankoffset = GetRank();
		int suitoffset = GetSuit();
		cout << Rank[rankoffset] << Suit[suitoffset];
	}
	else
		cout << "   ";

}
/**************************************************************
*	  Purpose:  op=
****************************************************************/
Card & Card::operator =(const Card & rhs)
{
	if (this != &rhs)
	{
		m_isRed = rhs.m_isRed;
		m_rank = rhs.m_rank;
		m_suit = rhs.m_suit;
		m_value = rhs.m_value;
	}
	return * this;
}
/**************************************************************
*	  Purpose:  dtor
****************************************************************/
Card::~Card()
{
}
/**************************************************************
*	  Purpose:  ctor
****************************************************************/
Card::Card()
	:m_suit(-1), m_rank(-1), m_value(0)
{
}
/**************************************************************
*	  Purpose:  ctor
****************************************************************/
Card::Card(int suit, int rank, int value)
	:m_suit(suit), m_rank(rank), m_value(value)
{
	if(suit == 1 || suit == 2)
		m_isRed = true;
	else
		m_isRed = false;
}
/**************************************************************
*	  Purpose:  copy ctor
****************************************************************/
Card::Card(const Card & in)
	:m_rank(in.m_rank), m_suit(in.m_suit), m_isRed(in.m_isRed), m_value(in.m_value)
{
}
/**************************************************************
*	  Purpose:  getter for red
****************************************************************/
bool Card::isRed()
{
	return m_isRed;
}
