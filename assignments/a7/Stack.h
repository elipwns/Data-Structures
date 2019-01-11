/************************************************************************
* Class: Stack
*
* Purpose: a wrapper around the linked list to use as a stack
*
* Manager functions:	
* 	Stack() - no arg ctor
*	~Stack() - dtor
*	Stack(const Stack<T> &) - copy ctor
*	Stack & operator=(const Stack<T> &) - overloaded op =
*
* Methods:		
*	void Push(T) - puts new data at the end of the list
*	T Pop() - deletes the last node and returns its data
*	T Peek() - returns the last node's data
*	int Size() - counts how big the list is
*	bool isEmpty() - returns true if empty
*************************************************************************/

#include "doublelinkedlist.h"

#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
public:
	Stack();
	~Stack();
	Stack(const Stack<T> &);
	Stack & operator=(const Stack<T> &);

	void Push(T);
	T Pop();
	T Peek();
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
************************************************************************/
template<typename T>
Stack<T>::Stack()
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
Stack<T>::~Stack()
{
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a stack by const ref
*
* Exit: uses op =
************************************************************************/
template<typename T>
Stack<T>::Stack(const Stack<T> & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: overloaded operator =
*
* Entry: passed a stack by const ref
*
* Exit: uses double linked list op =
************************************************************************/
template<typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & copy)
{
	m_list = copy.m_list
}
/**********************************************************************	
* Purpose: put an item on top of stack
*
* Entry:
*
* Exit: appends the data to the end of the list
************************************************************************/
template<typename T>
void Stack<T>::Push(T data)
{
	m_list.Append(data);
}
/**********************************************************************	
* Purpose: take item off stack
*
* Entry:
*
* Exit: deletes the item and returns its data
************************************************************************/
template<typename T>
T Stack<T>::Pop()
{
	if (m_list.isEmpty())
		throw Exception("List is empty");
	else
		return m_list.DeleteLast();
}
/**********************************************************************	
* Purpose: looks at data on top of stack
*
* Entry:
*
* Exit: returns the last nodes data
************************************************************************/
template<typename T>
T Stack<T>::Peek()
{
	return m_list.Last();
}
/**********************************************************************	
* Purpose: gets the size of the list
*
* Entry:
*
* Exit: returns the list size
************************************************************************/
template<typename T>
int Stack<T>::Size()
{
	return m_list.NumItems();
}
/**********************************************************************	
* Purpose: to tell if list is empty
*
* Entry:
*
* Exit: returns true if list is empty
************************************************************************/
template<typename T>
bool Stack<T>::isEmpty()
{
	if(m_list.isEmpty())
		return true;
	else
		return false;
}

#endif

