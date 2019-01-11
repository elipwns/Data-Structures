/************************************************************************
* Class: homecells
*
* Purpose: This class creates a dynamic one-dimensional array that can be 
* started at any base number. 
*
* Manager functions:	
* 	HomeCells() - no arg ctor
*	~HomeCells() - dtor
*	HomeCells(const HomeCells<T> &) - copy ctor
*	HomeCells<T> & operator =(const HomeCells<T> &) - overloaded op =
*
* Methods:		
*	void AddCard(Card) - adds a card to the homecells
*	bool CheckifComplete() - checks if full
*	void Display() - displays top card
*	Card Peek() - peeks at top card
*************************************************************************/
#include "card.h"
#include "stackArray.h"

#ifndef HOMECELLS
#define HOMECELLS

template<typename T>
class HomeCells
{
public:
	HomeCells();
	~HomeCells();
	HomeCells(const HomeCells<T> &);
	HomeCells<T> & operator =(const HomeCells<T> &);

	void AddCard(Card);
	bool CheckifComplete();
	void Display();
	Card Peek();
private:
	stackArray<T> m_stack;
};
/**********************************************************************	
* Purpose: no arg ctor
*
* Entry:
*
* Exit: sets the m_stack to an array of 13 stacks
************************************************************************/
template<typename T>
HomeCells<T>::HomeCells()
	:m_stack(stackArray<T>(13))
{
}
/**********************************************************************	
* Purpose: dtor
*
* Entry:
*
* Exit: 
************************************************************************/
template<typename T>
HomeCells<T>::~HomeCells()
{
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a homecell by const ref
*
* Exit: uses the op =
************************************************************************/
template<typename T>
HomeCells<T>::HomeCells(const HomeCells<T> & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: overloaded op =
*
* Entry: passed a homecell by const ref
*
* Exit: copies the stack and then returns this
************************************************************************/
template<typename T>
HomeCells<T> & HomeCells<T>::operator =(const HomeCells<T> & rhs)
{
	if (this != & rhs)
	{
		m_stack = rhs.m_stack;
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
template<typename T>
void HomeCells<T>::AddCard(Card in)
{
	m_stack.Push(in);
}
/**********************************************************************	
* Purpose: checks if stack is full
*
* Entry:
*
* Exit: return true if full stack.
************************************************************************/
template<typename T>
bool HomeCells<T>::CheckifComplete()
{
	if(m_stack.isFull())
		return true;
	else
		return false;
}
/**********************************************************************	
* Purpose: displays the top card
*
* Entry:
*
* Exit: looks at top card and displays it
************************************************************************/
template<typename T>
void HomeCells<T>::Display()
{
	Card tmp;

	tmp = m_stack.Peek();
	tmp.Display();
}
/**********************************************************************	
* Purpose: peeks at top card
*
* Entry:
*
* Exit: returns the peeped at card
************************************************************************/
template<typename T>
Card HomeCells<T>::Peek()
{
	return m_stack.Peek();
}

#endif