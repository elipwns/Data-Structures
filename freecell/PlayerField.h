/************************************************************************
* Class: player field
*
* Purpose: holds a stack of cards
*
* Manager functions:	
* 	PlayerField() - no arg ctor
*	~PlayerField() - dtor
*	PlayerField(const PlayerField<T> &) - copy ctor
*	PlayerField<T> & operator =(const PlayerField<T> &) - overloaded op =
*
* Methods:		
*	void PlaceCard(Card) - adds a card to stack
*	Card TakeCard() - takes top card off stack
*	Card Peek() - looks at top card
*	bool Display(int index) - displays the bottom card minus the index
*************************************************************************/
#include "StackLinked.h"

#ifndef PLAYERFIELD
#define PLAYERFIELD
template <typename T>
class PlayerField
{
public:
	PlayerField();
	~PlayerField();
	PlayerField(const PlayerField<T> &);
	PlayerField<T> & operator =(const PlayerField<T> &);

	void PlaceCard(Card);
	Card TakeCard();
	Card Peek();
	bool Display(int index);
	bool isEmpty();
	int Size();
private:
	StackLinked<T> m_stack_linked;
};
/**********************************************************************	
* Purpose: no arg ctor
*
* Entry:
*
* Exit: 
************************************************************************/
template <typename T>
PlayerField<T>::PlayerField()
{
	m_stack_linked.Push(T());
}
/**********************************************************************	
* Purpose: dtor
*
* Entry:
*
* Exit: purges the list
************************************************************************/
template <typename T>
PlayerField<T>::~PlayerField()
{
	m_stack_linked.purge();
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a player field by const ref
*
* Exit: uses op =
************************************************************************/
template <typename T>
PlayerField<T>::PlayerField(const PlayerField<T> & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: overloaded op =
*
* Entry: passed a player field by const ref
*
* Exit: copies the stack and returns this
************************************************************************/
template <typename T>
PlayerField<T> & PlayerField<T>::operator =(const PlayerField<T> & rhs)
{
	if(this != & rhs)
	{
		m_stack_linked = rhs.m_stack_linked;
	}
	return * this;
}
/**********************************************************************	
* Purpose: add a card to the stack
*
* Entry: passed a card
*
* Exit: pushes the card onto the stack
************************************************************************/
template <typename T>
void PlayerField<T>::PlaceCard(Card in)
{
	m_stack_linked.Push(in);
}
/**********************************************************************	
* Purpose: displays the card at bottom of stack minus index
*
* Entry: passed an int
*
* Exit: pops cards until gets to the one it needs to display
************************************************************************/
template <typename T>
bool PlayerField<T>::Display(int index)
{
	StackLinked<T> tempstack = m_stack_linked;
	Card tmpcard;
	
	int temp = (tempstack.isEmpty())?0:tempstack.Size() - (index + 1);
	
	for(int i = 0; i < temp; i++)
		tmpcard = tempstack.Pop();

	if(temp <= 0)
	{
		cout << "   ";
		return true;
	}
	else
	{
		tmpcard.Display();
		return false;
	}
}
/**********************************************************************	
* Purpose: pops a card off the stack
*
* Entry:
*
* Exit: returns the popped off card
************************************************************************/
template<typename T>
Card PlayerField<T>::TakeCard()
{
	return m_stack_linked.Pop();
}
/**********************************************************************	
* Purpose: peeks at top card
*
* Entry:
*
* Exit: returns that card
************************************************************************/
template<typename T>
Card PlayerField<T>::Peek()
{
	return m_stack_linked.Peek();
}

template<typename T>
bool PlayerField<T>::isEmpty()
{
	return m_stack_linked.Size() == 1;
}

template<typename T>
int PlayerField<T>::Size()
{
	return m_stack_linked.Size()-1;
}

#endif