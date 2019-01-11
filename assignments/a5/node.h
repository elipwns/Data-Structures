/************************************************************************
* Class: Node
*
* Purpose: holds the next and prev pointers as well as the data
*
* Manager functions:	
* 	Node ( )
* 		The default data is zero and nullptr for prev and next
*	Node (T data)
*		sets data to the parameter. prev and next are set to nullptr
*	Node (const Node & copy)
*		copies the data
*	operator = (const Array & copy)
*		sets this = to copy
*	~Node()
*		sets data to 0 and nullptr for prev and next
*
* Methods:		
*	getdata() returns the data
*************************************************************************/

#include <iostream>
using std::ostream;

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
	template <typename T> friend class ForwardIterator;
	template <typename T> friend class BackwardsIterator;
	template <typename T> friend class DoubleLinkedList;
	template <typename T>
	friend ostream & operator <<(ostream & stream, Node<T> & n1);
private:
	T m_data;
	Node * m_next;
	Node * m_prev;
	bool uninit;
	Node();
	Node(T data);
public:
	~Node();
	Node(const Node &);
	Node & operator =(const Node &);
	T getData() const;
	T & getData();
};

/**********************************************************************	
* Purpose: overloaded << operator
*
* Entry: passed a stream and node by ref
*
* Exit: if there is a node display its data otherwise display n/a
*
************************************************************************/
template<typename T>
ostream & operator <<(ostream & stream, Node<T> & n1)
{
	if (&n1 == nullptr)
		return stream << "Not Initialized";
	return stream << n1.getData();
}
/**********************************************************************	
* Purpose: node no arg ctor
*
* Entry: 
*
* Exit:sets data to default, next and prev to nullptr and uninitialized to true
*
************************************************************************/
template<typename T>
Node<T>::Node()
	:m_data(T()), m_next(nullptr), m_prev(nullptr), uninit(true)
{
}
/**********************************************************************	
* Purpose: node 1 arg ctor
*
* Entry: passed a T data
*
* Exit: sets the data to the parameter, next and prev to nullptr
*	and uninitalized to false
*
************************************************************************/
template<typename T>
Node<T>::Node(T data)
	:m_data(data), m_next(nullptr), m_prev(nullptr), uninit(false)
{
}
/**********************************************************************	
* Purpose: node dtor
*
* Entry: 
*
* Exit: sets data to 0, prev and next to null ptr and uninitalized to true
*
************************************************************************/
template<typename T>
Node<T>::~Node()
{
	m_data = 0;
	m_next = nullptr;
	m_prev = nullptr;
	uninit = true;
}
/**********************************************************************	
* Purpose: node copy ctor
*
* Entry: passed a node by const ref
*
* Exit: sets the data to copies data
*
************************************************************************/
template<typename T>
Node<T>::Node(const Node & copy)
{
	m_data = copy.m_data;
	m_next = copy.m_next;
	m_prev = copy.m_prev;
	uninit = copy.uninit;
}
/**********************************************************************	
* Purpose: overloaded operator =
*
* Entry: passed a node by const ref
*
* Exit: checks for self assignemnt and then copies the data over
*
************************************************************************/
template<typename T>
Node<T> & Node<T>::operator =(const Node & rhs)
{
	if(this != & rhs)
	{
		m_data = rhs.m_data;
		m_next = rhs.m_next;
		m_prev = rhs.m_prev;
		uninit = rhs.uninit;
	}
	return * this;
}
/**********************************************************************	
* Purpose: returns the data
*
* Entry: 
*
* Exit: returns data
*
************************************************************************/
template<typename T>
T Node<T>::getData()const
{
	return m_data;
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
T & Node<T>::getData()
{
	return m_data;
}


#endif