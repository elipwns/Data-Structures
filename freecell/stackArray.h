/************************************************************************
* Class: stackArray
*
* Purpose: wrapper around array to make a stackArray
*
* Manager functions:	
* 	stackArray(int stacksize) - 1 arg ctor, passed the stackArray size
*	~stackArray() - dtor
*	stackArray(const stackArray<T> &) - copy ctor
*	stackArray<T> & operator=(const stackArray<T> &) - overloaded op =
*
* Methods:		
*	void Push(T) - put item on top of stackArray
*	T Pop() - take an item off the stackArray
*	T Peek() - look at item on top of stackArray
*	int Size() - returns the size of the stackArray
*	bool isEmpty() - returns true if stackArray is empty
*	bool isFull() - returns true is stackArray is full
*************************************************************************/

#include "array.h"
#include "exception.h"

#ifndef STACKARRAY_H
#define STACKARRAY_H

template<typename T>
class stackArray
{
public:
	stackArray(int stacksize = 0);
	~stackArray();
	stackArray(const stackArray<T> &);
	stackArray<T> & operator=(const stackArray<T> &);

	void Push(T);
	T Pop();
	T Peek();
	int Size();
	bool isEmpty();
	bool isFull();
private:
	Array<T> m_array;
	int m_index;
};
/**********************************************************************	
* Purpose: 1 arg ctor
*
* Entry: passed an int
*
* Exit: sets the length to the stacksize plus 1 to know when you are at
*	the start of the list
*
************************************************************************/
template<typename T>
stackArray<T>::stackArray(int stacksize = 0)
{
	m_array.SetLength(stacksize + 1);
	m_index = 0;
}
/**********************************************************************	
* Purpose: dtor
*
* Entry:
*
* Exit: resets index
*
************************************************************************/
template<typename T>
stackArray<T>::~stackArray()
{
	m_index = 0;
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a stackArray by const ref
*
* Exit: uses op =
*
************************************************************************/
template<typename T>
stackArray<T>::stackArray(const stackArray<T> & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: overloaded op =
*
* Entry: passed a stackArray by const ref
*
* Exit: copies the pointers
************************************************************************/
template<typename T>
stackArray<T> & stackArray<T>::operator=(const stackArray<T> & copy)
{
	if(this != &copy)
	{
		m_array = copy.m_array;
		m_index = copy.m_index;
	}
	return * this;
}
/**********************************************************************	
* Purpose: put an item on top of the stackArray
*
* Entry: passed a T
*
* Exit: inc index, set T to top of stackArray
*
************************************************************************/
template<typename T>
void stackArray<T>::Push(T data)
{
	if(isFull())
		throw Exception("stackArray is full ~ Overflow");
	else
		m_array[++m_index] = data;
}
/**********************************************************************	
* Purpose: takes the first item off the top of the stackArray
*
* Entry: 
*
* Exit: if empty throw exception else return the item and dec index
*
************************************************************************/
template<typename T>
T stackArray<T>::Pop()
{
	if(isEmpty())
		throw Exception("stackArray is empty ~ underflow");
	else
		return m_array[m_index--];
}
/**********************************************************************	
* Purpose: to look at the item on top of the stackArray
*
* Entry: 
*
* Exit: returns the T at the top of the stackArray
*
************************************************************************/
template<typename T>
T stackArray<T>::Peek()
{
	return m_array[m_index];
}
/**********************************************************************	
* Purpose: returns the size of the stackArray
*
* Entry: 
*
* Exit: returns the size of the stackArray
*
************************************************************************/
template<typename T>
int stackArray<T>::Size()
{
	return (m_array.GetLength() - 1);
}
/**********************************************************************	
* Purpose: checks to see if the list is empty
*
* Entry: 
*
* Exit: returns true if list is empty else returns false
*
************************************************************************/
template<typename T>
bool stackArray<T>::isEmpty()
{
	if(m_index == 0)
		return true;
	else
		return false;
}
/**********************************************************************	
* Purpose: checks to see if stackArray is full
*
* Entry: 
*
* Exit: returns true if stackArray is full else returns false
*
************************************************************************/
template<typename T>
bool stackArray<T>::isFull()
{
	if(m_index ==( m_array.GetLength() - 1))
		return true;
	else 
		return false;
}

#endif 