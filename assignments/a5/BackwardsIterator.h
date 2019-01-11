/************************************************************************
* Class: Backward Iterator
*
* Purpose: concrete list iterator designed to traverse backwards
*
* Manager functions:	
*	Backward Iterator (double linked list &)
*		sets up the pointers
*	Backward Iterator (const Backward Iterator & copy)
*		copies the pointers
*	operator = (const Backward Iterator & copy)
*		copies the pointers
*	~Backward Iterator()
*		dtor
*
* Methods:		
*	void MoveNext() - traverse the list by 1
*	void Reset() - reset to tail
*	bool IsDone() - returns true if at begining of list
*	T GetCurrent()const - returns the data
*	T & GetCurrent() - returns the data by ref
*************************************************************************/

#include "ListIterator.h"
#include "doublelinkedlist.h"

#ifndef BACKWARDSITERATOR_H
#define BACKWARDSITERATOR_H
template<typename T>
class BackwardsIterator:public ListIterator<T>
{
public:
	BackwardsIterator(DoubleLinkedList<T> &);
	~BackwardsIterator();
	BackwardsIterator(const BackwardsIterator &);
	BackwardsIterator & operator = (const BackwardsIterator &);

	void MoveNext();
	void Reset();
	bool IsDone();
	T GetCurrent()const;
	T & GetCurrent();
protected:
	Node<T> * m_Start;
	Node<T> * m_End;
	Node<T> * m_Current; 
};
/**********************************************************************	
* Purpose: 1 arg ctor
*
* Entry: passed a double linked list by ref
*
* Exit: sets up the pointers
*
************************************************************************/
template<typename T>
BackwardsIterator<T>::BackwardsIterator(DoubleLinkedList<T> & list)
{
	m_Start = list.getHead();
	m_End = list.getTail();
	m_Current = m_End;
}
/**********************************************************************	
* Purpose: dtor
*
* Entry: 
*
* Exit: sets the pointers to nullptr
*
************************************************************************/
template<typename T>
BackwardsIterator<T>::~BackwardsIterator()
{
	m_Start = nullptr;
	m_End = nullptr;
	m_Current = nullptr;
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry:passed a forward iterator by const ref
*
* Exit: uses the op =
*
************************************************************************/
template<typename T>
BackwardsIterator<T>::BackwardsIterator(const BackwardsIterator & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: overloaded operator =
*
* Entry:passed a forward iterator by const ref
*
* Exit:checks for self assignment and then copies over the pointers
*
************************************************************************/
template<typename T>
BackwardsIterator<T> & BackwardsIterator<T>::operator =(const BackwardsIterator & that)
{
	if(this != & that)
	{
		m_Start = that.m_Start;
		m_End = that.m_End;
		m_Current = that.m_Current;
	}
	return * this;
}
/**********************************************************************	
* Purpose: sets current to next item
*
* Entry: 
*
* Exit: sets current to currents prev
*
************************************************************************/
template<typename T>
void BackwardsIterator<T>::MoveNext()
{
	m_Current = m_Current->m_prev;
}
/**********************************************************************	
* Purpose: to reset the list
*
* Entry: 
*
* Exit: sets current to end
*
************************************************************************/
template<typename T>
void BackwardsIterator<T>::Reset()
{
	m_Current = m_End;
}
/**********************************************************************	
* Purpose: checks to see if at start of list
*
* Entry:
*
* Exit: returns true if at the start of list, else return false
*
************************************************************************/
template<typename T>
bool BackwardsIterator<T>::IsDone()
{
	if(m_Current == m_Start)
		return true;
	return false;
}
/**********************************************************************	
* Purpose: returns the data
*
* Entry:
*
* Exit: returns the data
*
************************************************************************/
template<typename T>
T BackwardsIterator<T>::GetCurrent()const
{
	return m_Current->getData();
}
/**********************************************************************	
* Purpose: returns data by ref
*
* Entry: 
*
* Exit: returns data by ref
*
************************************************************************/
template<typename T>
T & BackwardsIterator<T>::GetCurrent()
{
	return m_Current->getData();
}
#endif