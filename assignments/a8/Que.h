/************************************************************************
* Class: Que
*
* Purpose: wrapper around array class to act as a circle que
*
* Manager functions:	
* 	Que(int items) - ctor, sets the size of que to the parameter
*	~Que() - dtor
*	Que(const Que &) - copy ctor
*	Que & operator=(const Que &) - overloaded operator =
*
* Methods:		
*	void EnQue(T data) - add an item to the que
*	T DeQue() - take off and item from the que
*	T & Front() - get the address of the first element
*	int Size() - returns the size of the que
*	bool isEmpty() - returns true if empty
*	bool isFull() - returns true if full
*************************************************************************/
#include "array.h"
#include "exception.h"
#ifndef QUE_H
#define QUE_H

template<typename T>
class Que
{
public:
	Que(int items);
	~Que();
	Que(const Que &);
	Que & operator=(const Que &);

	void EnQue(T data);
	T DeQue();
	T & Front();
	int Size();
	bool isEmpty();
	bool isFull();
private:
	Array<T> m_array;
	int m_size;
	int m_tail;
	int m_front;
	bool m_empty;
};
/**********************************************************************	
* Purpose: que 1 arg ctor
*
* Entry: passed an int
*
* Exit: sets the front and tail to 0, the size to the int and empty to true
*
************************************************************************/
template<typename T>
Que<T>::Que(int items)
	:m_tail(0), m_front(0), m_size(items), m_empty(true)
{
	m_array.SetLength(items);
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
* Exit: uses the operator =
*
************************************************************************/
template<typename T>
Que<T>::Que(const Que & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: overloaded operator =
*
* Entry: passed a que by const ref
*
* Exit: copies over the data
*
************************************************************************/
template<typename T>
Que<T> & Que<T>::operator=(const Que & copy)
{
	m_array = copy.m_array;
	m_tail = copy.m_tail;
	m_front = copy.m_front;
	m_size = copy.m_size;
	m_empty = copy.m_empty;
}
/**********************************************************************	
* Purpose: places an item onto the end of the que
*
* Entry: passed a T
*
* Exit: places the T onto the end of the que and updates the tail pointer
*
************************************************************************/
template<typename T>
void Que<T>::EnQue(T data)
{
	if(isFull())
		throw Exception("Que Full");
	
	if(m_tail == m_size - 1)
		m_tail = -1;
	if(isEmpty())
		m_array[0] = data;
	else
		m_array[++m_tail] = data;
	m_empty = false;
}
/**********************************************************************	
* Purpose: takes off the first item in the que
*
* Entry: 
*
* Exit: checks for empty list and then returns the first item
*
************************************************************************/
template<typename T>
T Que<T>::DeQue()
{
	if(m_front == m_tail && m_empty)
		throw Exception("Que Empty");
	if(m_front == m_tail && !m_empty)
		m_empty = true;

	if(!m_empty)
	{
		int temp = m_front;
		if (m_front == m_size)
		{
			m_front = 0;
			temp = 0;
		}
		else
		{
			++m_front;
		}
		return m_array[temp];
	}
	else
		throw Exception("Que Empty");

}
/**********************************************************************	
* Purpose: returns the first item in the que by ref to be able to change it
*
* Entry: 
*
* Exit: returns the front of the que by ref
*
************************************************************************/
template<typename T>
T & Que<T>::Front()
{
	return m_array[m_front];
}
/**********************************************************************	
* Purpose: returns the size of the array
*
* Entry: 
*
* Exit: returns the size of the array
*
************************************************************************/
template<typename T>
int Que<T>::Size()
{
	return m_size;
}
/**********************************************************************	
* Purpose: returns true if que is empty
*
* Entry: 
*
* Exit: returns true if list is empty
*
************************************************************************/
template<typename T>
bool Que<T>::isEmpty()
{
	if (m_empty)
		return true;
	else
		return false;
}
/**********************************************************************	
* Purpose: returns true if que is full
*
* Entry:
*
* Exit: checks to see if the tail's next is the head, if so return true
*
************************************************************************/
template<typename T>
bool Que<T>::isFull()
{
	if(m_tail == m_size - 1 && m_front == 0)
		return true;
	if(m_tail + 1 == m_front)
		return true;
	else
		return false;
}
#endif

