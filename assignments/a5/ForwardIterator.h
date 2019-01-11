/************************************************************************
* Class: Forward Iterator
*
* Purpose: concrete list iterator designed to traverse forwards
*
* Manager functions:	
*	Forward Iterator (double linked list &)
*		sets up the pointers
*	Forward Iterator (const Forward Iterator & copy)
*		copies the pointers
*	operator = (const Forward Iterator & copy)
*		copies the pointers
*	~Forward Iterator()
*		dtor
*
* Methods:		
*	void MoveNext() - traverse the list by 1
*	void Reset() - reset to head
*	bool IsDone() - returns true if at end of list
*	T GetCurrent()const - returns the data
*	T & GetCurrent() - returns the data by ref
*************************************************************************/

#include "ListIterator.h"
#include "doublelinkedlist.h"
#ifndef FORWARDITERATOR_H
#define FORWARDITERATOR_H

template<typename T>
class ForwardIterator:public ListIterator<T>
{
public:
	ForwardIterator(DoubleLinkedList<T> &);
	~ForwardIterator();
	ForwardIterator(const ForwardIterator<T> &);
	ForwardIterator & operator =(const ForwardIterator<T> &);

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
ForwardIterator<T>::ForwardIterator(DoubleLinkedList<T> & list)
{
	m_Start = list.getHead();
	m_End = list.getTail();
	m_Current = m_Start;
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
ForwardIterator<T>::~ForwardIterator()
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
ForwardIterator<T>::ForwardIterator(const ForwardIterator<T> & that)
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
ForwardIterator<T> & ForwardIterator<T>::operator =(const ForwardIterator<T> & that)
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
* Exit: sets current to currents next
*
************************************************************************/
template<typename T>
void ForwardIterator<T>::MoveNext()
{
	m_Current = m_Current->m_next;
}
/**********************************************************************	
* Purpose: to reset the list
*
* Entry: 
*
* Exit: sets current to start
*
************************************************************************/
template<typename T>
void ForwardIterator<T>::Reset()
{
	m_Current = m_Start;
}
/**********************************************************************	
* Purpose: checks to see if at end of list
*
* Entry:
*
* Exit: returns true if at the end of list, else return false
*
************************************************************************/
template<typename T>
bool ForwardIterator<T>::IsDone()
{
	if(m_Current == m_End)
		return true;
	else
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
T ForwardIterator<T>::GetCurrent()const
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
T & ForwardIterator<T>::GetCurrent()
{
	return m_Current->getData();
}
#endif