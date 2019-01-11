/************************************************************************
* Class: Array
*
* Purpose: This class creates a dynamic one-dimensional array that can be * started at any base. 
*
* Manager functions:	
* 	ListIterator();
*	virtual ~ListIterator();
*	
* Methods:		
*	void MoveNext() pure virtual
*	void Reset() pure virutal
*	T GetCurrent()const pure virtual
*	T & GetCurrent() pure virtual
*	bool IsDone() pure virtual
*************************************************************************/

#include "AbstractIterator.h"
#ifndef LISTITERATOR_H
#define LISTITERATOR_H


template<typename T>
class ListIterator:public AbstractIterator<T>
{
public:
	ListIterator();
	virtual ~ListIterator();
	virtual void MoveNext() = 0;
	virtual void Reset() = 0;
	virtual T GetCurrent()const = 0;
	virtual T & GetCurrent() = 0;
	virtual bool IsDone() = 0;
protected:
	Node<T> * m_Start;
	Node<T> * m_End;
	Node<T> * m_Current; 
};
/**********************************************************************	
* Purpose: no arg ctor
*
* Entry:
*
* Exit: sets pointers to nullptr
************************************************************************/
template<typename T>
ListIterator<T>::ListIterator()
	:m_Current(nullptr), m_End(nullptr), m_Start(nullptr)
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
ListIterator<T>::~ListIterator()
{
}

#endif