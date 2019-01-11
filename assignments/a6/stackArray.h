/************************************************************************
* Class: stack
*
* Purpose: wrapper around array to make a stack
*
* Manager functions:	
* 	Stack(int stacksize) - 1 arg ctor, passed the stack size
*	~Stack() - dtor
*	Stack(const Stack<T> &) - copy ctor
*	Stack<T> & operator=(const Stack<T> &) - overloaded op =
*
* Methods:		
*	void Push(T) - put item on top of stack
*	T Pop() - take an item off the stack
*	T Peek() - look at item on top of stack
*	int Size() - returns the size of the stack
*	bool isEmpty() - returns true if stack is empty
*	bool isFull() - returns true is stack is full
*************************************************************************/

#include "array.h"
#include "exception.h"

#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
public:
	Stack(int stacksize);
	~Stack();
	Stack(const Stack<T> &);
	Stack<T> & operator=(const Stack<T> &);

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
Stack<T>::Stack(int stacksize)
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
Stack<T>::~Stack()
{
	m_index = 0;
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a stack by const ref
*
* Exit: uses op =
*
************************************************************************/
template<typename T>
Stack<T>::Stack(const Stack<T> & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: overloaded op =
*
* Entry: passed a stack by const ref
*
* Exit: copies the pointers
************************************************************************/
template<typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & copy)
{
	m_array = copy.m_array;
	m_index = copy.m_index;
}
/**********************************************************************	
* Purpose: put an item on top of the stack
*
* Entry: passed a T
*
* Exit: inc index, set T to top of stack
*
************************************************************************/
template<typename T>
void Stack<T>::Push(T data)
{
	if(isFull())
		throw Exception("Stack is full ~ Overflow");
	else
		m_array[++m_index] = data;
}
/**********************************************************************	
* Purpose: takes the first item off the top of the stack
*
* Entry: 
*
* Exit: if empty throw exception else return the item and dec index
*
************************************************************************/
template<typename T>
T Stack<T>::Pop()
{
	if(isEmpty())
		throw Exception("Stack is empty ~ underflow");
	else
		return m_array[m_index--];
}
/**********************************************************************	
* Purpose: to look at the item on top of the stack
*
* Entry: 
*
* Exit: returns the T at the top of the stack
*
************************************************************************/
template<typename T>
T Stack<T>::Peek()
{
	return m_array[m_index];
}
/**********************************************************************	
* Purpose: returns the size of the stack
*
* Entry: 
*
* Exit: returns the size of the stack
*
************************************************************************/
template<typename T>
int Stack<T>::Size()
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
bool Stack<T>::isEmpty()
{
	if(m_index == 0)
		return true;
	else
		return false;
}
/**********************************************************************	
* Purpose: checks to see if stack is full
*
* Entry: 
*
* Exit: returns true if stack is full else returns false
*
************************************************************************/
template<typename T>
bool Stack<T>::isFull()
{
	if(m_index ==( m_array.GetLength() - 1))
		return true;
	else 
		return false;
}

#endif 