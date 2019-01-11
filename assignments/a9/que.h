/************************************************************************
* Class: Que
*
* Purpose: creates a wrapper around the linked list class to act as a que
*
* Manager functions:	
*	Que();
*	~Que();
*	Que(const Que<T> &);
*	Que<T> & operator =(const Que<T> &);
*
* Methods:		
*	void Enqueue(T data);
*	T Dequeue();
*	T & Front();
*	int Size();
*	bool isEmpty();
*************************************************************************/
#include "doublelinkedlist.h"

#ifndef QUE_H
#define QUE_H

template<typename T>
class Que
{
public:
	Que();
	~Que();
	Que(const Que<T> &);
	Que<T> & operator =(const Que<T> &);

	void Enqueue(T data);
	T Dequeue();
	T & Front();
	int Size();
	bool isEmpty();
private:
	DoubleLinkedList<T> m_list;
};
/**********************************************************************	
* Purpose: no arg ctor
*
* Entry:
*
* Exit:
*
************************************************************************/
template<typename T>
Que<T>::Que()
{
}
/**********************************************************************	
* Purpose: dtor
*
* Entry: 
*
* Exit: 
*
************************************************************************/
template<typename T>
Que<T>::~Que()
{
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a que by const ref
*
* Exit: uses op =
*
************************************************************************/
template<typename T>
Que<T>::Que(const Que<T> & that)
{
	m_list = that.m_list;
}
/**********************************************************************	
* Purpose: overloaded operator =
*
* Entry: passed a que by const ref
*
* Exit: checks for self assignment, uses op= of the list class
*
************************************************************************/
template<typename T>
Que<T> & Que<T>::operator =(const Que<T> & rhs)
{
	if (this != &rhs)
	{
		m_list = rhs.m_list;
	}
	return * this;
}
/**********************************************************************	
* Purpose: adds an item to the end of the que
*
* Entry: passed a T
*
* Exit: appends the T to the list
*
************************************************************************/
template<typename T>
void Que<T>::Enqueue(T data)
{
	m_list.Append(data);
}
/**********************************************************************	
* Purpose: removes the first item
*
* Entry: 
*
* Exit: returns the first item and then extracts it
*
************************************************************************/
template<typename T>
T Que<T>::Dequeue()
{
	if(m_list.isEmpty())
		throw Exception("List is Empty");
	T temp = m_list.First();
	m_list.Extract(temp);
	return temp;
}
/**********************************************************************	
* Purpose: returns the front of the que by ref
*
* Entry: 
*
* Exit: returns the first item in the list
*
************************************************************************/
template<typename T>
T & Que<T>::Front()
{
	return m_list.First();
}
/**********************************************************************	
* Purpose: returns the size of the que
*
* Entry: 
*
* Exit: returns the number of items in the list
*
************************************************************************/
template<typename T>
int Que<T>::Size()
{
	return m_list.NumItems();
}
/**********************************************************************	
* Purpose: checks to see if que is empty
*
* Entry: 
*
* Exit: returns what is returned by lists check for empty
************************************************************************/
template<typename T>
bool Que<T>::isEmpty()
{
	return m_list.isEmpty();
}

#endif
