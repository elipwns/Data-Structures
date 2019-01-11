/************************************************************************
* Class: Double Linked List
*
* Purpose: creates and manages a double linked list for ease of use later
*
* Manager functions:	
* 	Double Linked List ( )
* 		creates a new unititialized and points head and tail to it
*	Double Linked List (const Double Linked List & copy)
*		deep copies the list
*	operator = (const Double Linked List & copy)
*		deep copies the list
*	~Double Linked List()
*		deletes the nodes
*
* Methods:		
*	bool isEmpty() - returns true if list is empty
*	const T & First()const - returns the first data element
*	const T & Last()const - returns the last data element
*	void Prepend(T) - prepends an item to the list
*	void Append(T) - appends an item to the list
*	void Purge() - deletes all items from list
*	void Extract(T data) - deletes one item from the list
*	void InsertAfter(T data, T newdata) - inserts an item after another item
*	void InsertBefore(T data, T newdata) - inserts an item before another item
*	void PrintForwards() - prints the list forwards
*	void PrintBackwards() - prints the list backwards
*	Node<T> * getHead() - returns the pointer to the head node
*	Node<T> * getTail() - returns the pointer to the tail node
*************************************************************************/

#include "node.h"
#include <iostream>
using std::cout;
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template<typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList<T> &);
	DoubleLinkedList<T> & operator =(const DoubleLinkedList<T> &);

	bool isEmpty();
	const T & First()const;
	const T & Last()const;
	void Prepend(T);
	void Append(T);
	void Purge();
	void Extract(T data);
	void InsertAfter(T data, T newdata);
	void InsertBefore(T data, T newdata);
	T DeleteLast();
	void PrintForwards();
	void PrintBackwards();
	int NumItems();

	Node<T> * getHead();
	Node<T> * getTail();
private:
	Node<T> * m_head;
	Node<T> * m_tail;
	
};
/**********************************************************************	
* Purpose: no arg ctor
*
* Entry: 
*
* Exit: creates a new uninitialized node and points head and tail at it
*
************************************************************************/
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_head = new Node<T>();
	m_tail = m_head;
}
/**********************************************************************	
* Purpose: dtor
*
* Entry: 
*
* Exit: deletes all the nodes
*
************************************************************************/
template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Purge();
	m_head = nullptr;
	m_tail = nullptr;
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a double linked list by const ref
*
* Exit: deep copies the data
*
************************************************************************/
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T> & copy)
{
	if(copy.m_head != nullptr)
	{
		Node<T> * temp;
		Node<T> * tempbefore;
		Node<T> * copyhead = copy.m_head;
		m_head = new Node<T>(copy.m_head->m_data);
		
		if(copyhead->m_next != nullptr)
		{
			copyhead = copyhead->m_next;
			temp = m_head;
			while(copyhead->m_next != nullptr)
			{
				tempbefore = temp;
				temp->m_next = new Node<T>(copyhead->m_data);
				copyhead = copyhead->m_next;
				temp = temp->m_next;
				temp->m_prev = tempbefore;
			}
			m_tail = temp;
			temp->m_next = nullptr;
		}
		else
			m_tail = m_head;
	}
}
/**********************************************************************	
* Purpose: overloaded operator =
*
* Entry: passed a double linked list by const ref
*
* Exit: deep copies the data
*
************************************************************************/
template<typename T>
DoubleLinkedList<T> & DoubleLinkedList<T>::operator =(const DoubleLinkedList<T> & copy)
{
	if(this != &copy && copy.m_head != nullptr)
	{
		this->Purge();

		Node<T>* trail = copy.m_head;

		while(trail->m_next != nullptr)
		{
			this->Append(trail->m_data);
			trail = trail->m_next;
		}
		this->Append(trail->m_data);
	}
	else
	{
		m_head = nullptr;
		m_tail = nullptr;
	}
	return *this;
}

/**********************************************************************	
* Purpose: checks for empty list
*
* Entry: 
*
* Exit: returns true if list is empty
*
************************************************************************/
template<typename T>
bool DoubleLinkedList<T>::isEmpty()
{
	if(m_head == nullptr || m_head->uninit)
		return true;
	else
		return false;
}
/**********************************************************************	
* Purpose: returns the data of the first node
*
* Entry: 
*
* Exit: checks for empty list and then returns the first node's data
*
************************************************************************/
template<typename T>
const T & DoubleLinkedList<T>::First()const
{
	if(m_head == nullptr || m_head->uninit)
		throw "No First";
	else
		return m_head->m_data;
}
/**********************************************************************	
* Purpose: returns the data of the last node
*
* Entry: 
*
* Exit: checks for empty list and then returns the last node's data by ref
*
************************************************************************/
template<typename T>
const T & DoubleLinkedList<T>::Last()const
{
	if(m_tail == nullptr || m_tail->uninit)
		throw "No Last";
	else
		return m_tail->m_data;
}
/**********************************************************************	
* Purpose: adds item to start of list
*
* Entry: passed a T
*
* Exit: adds an item to the start of the list and updates the head pointer
*
************************************************************************/
template<typename T>
void DoubleLinkedList<T>::Prepend(T data)
{
	if(m_head->uninit)
	{
		delete m_head;
		m_head = nullptr;
	}
	if(m_head != nullptr && !m_head->uninit)
	{
		Node<T> * temp = m_head->m_prev;
		temp = new Node<T>(data);
		temp->m_next = m_head;
		m_head->m_prev = temp;
		m_head = temp;
	}
	else
	{
		m_head = new Node<T>(data);
		m_tail = m_head;
	}
}
/**********************************************************************	
* Purpose: sets the data to the end of the list
*
* Entry: passed a T
*
* Exit: sets the data to the end of the list and updates the tail pointer
*
************************************************************************/
template<typename T>
void DoubleLinkedList<T>::Append(T data)
{
	if(m_tail == nullptr || m_tail->uninit)
	{
		delete m_tail;		
		m_head = new Node<T>(data);
		m_tail = m_head;
	}
	else
	{
		Node<T> * temp = m_tail->m_next;
		temp = new Node<T>(data);
		temp->m_prev = m_tail;
		m_tail->m_next = temp;
		m_tail = temp;
	}
}
/**********************************************************************	
* Purpose: deletes all info from the list
*
* Entry: 
*
* Exit: traverses the list deleting every element
*
************************************************************************/
template<typename T>
void DoubleLinkedList<T>::Purge()
{
	while(m_head != m_tail)
	{
		m_head = m_head->m_next;
		delete m_head->m_prev;
	}
	delete m_head;
	m_head = nullptr;
	m_tail = nullptr;
}
/**********************************************************************	
* Purpose: takes a piece of data out of the list
*
* Entry: passed a T to take out
*
* Exit: searches for the data and then takes it out of the list
*	and fixes their nexts, prevs, and head/tail pointers if it applies
*
************************************************************************/
template<typename T>
void DoubleLinkedList<T>::Extract(T data)
{
	if(m_head == nullptr || m_head->uninit)
		throw "List Empty";
	Node<T> * temp = m_head;
	while(temp->m_data != data)
		temp = temp->m_next;
	if(temp->m_prev == nullptr)
	{
		if(temp->m_next == nullptr)
		{
			delete temp;
			m_head = nullptr;
			m_tail = nullptr;
		}
		else
		{
			m_head = temp->m_next;
			delete temp;
			m_head->m_prev = nullptr;
		}
	}
	else if (temp->m_next == nullptr)
	{
		m_tail = temp->m_prev;
		delete temp;
		m_tail->m_next = nullptr;
	}
	else
	{
		Node<T> * tempafter = temp->m_next;
		Node<T> * before = temp->m_prev;
		before->m_next = tempafter;
		delete temp;
		tempafter->m_prev = before;		
	}
}
/**********************************************************************	
* Purpose: inserts new data after old data
*
* Entry: passed two T's
*
* Exit: finds the old data and places the new data after it
*
************************************************************************/
template<typename T>
void DoubleLinkedList<T>::InsertAfter(T newdata, T data)
{
	bool found = false;
	if(m_head == nullptr || m_head->uninit)
		throw "List Empty";
	Node<T> * temp = m_head;
	if(temp == m_tail)
		found = true;
	while(temp != m_tail && !found)
	{
		if(temp->m_data == data)
			found = true;
		else
			temp = temp->m_next;
		if(temp->m_data == data)
			found = true;
	}
	if(!found)
		throw "Item not in list";
	if(temp->m_next == nullptr)
	{
		Node<T> * temp2 = new Node<T>(newdata);
		temp2->m_prev = temp;
		m_tail = temp2;
		temp->m_next = temp2;
	}
	else
	{
		Node<T> * temp2 = temp->m_next;
		Node<T> * after = new Node<T>(newdata);
		temp->m_next = after;
		after->m_prev = temp;
		temp2->m_prev = after;
		after->m_next = temp2;
	}
}
/**********************************************************************	
* Purpose: inserts the new data to before the data
*
* Entry: passed two T's
*
* Exit: traverses the list until it finds the data, then places the new
*	data before it
************************************************************************/
template<typename T>
void DoubleLinkedList<T>::InsertBefore(T newdata, T data)
{
	if(m_head == nullptr || m_head->uninit)
		throw "List Empty";
	Node<T> * temp = m_head;
	while(temp->m_data != data)
	{
		if(temp->m_next == nullptr)
			throw "Item not in list";
		temp = temp->m_next;
	}
	if(temp->m_prev == nullptr)
	{
		temp->m_prev = new Node<T>(newdata);
		m_head = temp->m_prev;
		m_head->m_next = temp;
		temp->m_prev = m_head;
	}
	else
	{
		Node<T> * before = temp->m_prev;
		before->m_next = new Node<T>(newdata);
		before->m_next->m_next = temp;
		temp->m_prev = before->m_next;
		before->m_next->m_prev = before;
	}
}
/**********************************************************************	
* Purpose: getter for head
*
* Entry: 
*
* Exit: returns the head pointer
*
************************************************************************/
template<typename T>
Node<T> * DoubleLinkedList<T>::getHead()
{
	return m_head;
}
/**********************************************************************	
* Purpose: returns the tail pointer
*
* Entry: 
*
* Exit: returns the tail pointer
*
************************************************************************/
template<typename T>
Node<T> * DoubleLinkedList<T>::getTail()
{
	return m_tail;
}
/**********************************************************************	
* Purpose: displays the list from the front
*
* Entry: 
*
* Exit: while not at end of list display the data
*
************************************************************************/
template<typename T>
void DoubleLinkedList<T>::PrintForwards()
{
	Node<T> * temp = m_head;
	while(temp != m_tail)
	{
		cout << temp->m_data << "\n";
		temp = temp->m_next;
	}
	cout << m_tail->m_data << "\n";
}
/**********************************************************************	
* Purpose: displays the list backwards
*
* Entry:
*
* Exit: while not at the top of the list print out the data
*
************************************************************************/
template<typename T>
void DoubleLinkedList<T>::PrintBackwards()
{
	Node<T> * temp = m_tail;
	while(temp != m_head)
	{
		cout << temp->m_data << "\n";
		temp = temp->m_prev;
	}
	cout << m_head->m_data << "\n";
}
/**********************************************************************	
* Purpose: deletes the last item in the list
*
* Entry:
*
* Exit: deletes item and returns its data for use in pop function
************************************************************************/
template<typename T>
T DoubleLinkedList<T>::DeleteLast()
{
	T save;
	if(m_head == nullptr)
		save = T();
		//throw Exception("empty list cannot delete ");
	else if(m_head != m_tail)
	{
		m_tail = m_tail->m_prev;
		save = m_tail->m_next->m_data;
		delete m_tail->m_next;
		m_tail->m_next = nullptr;
	}
	else
	{
		save = m_head->m_data;
		delete m_head;
		m_tail = nullptr;
		m_head = nullptr;
	}
	return save;
}
/**********************************************************************	
* Purpose: counts number of items in linked list
*
* Entry:
*
* Exit: returns the number of items
*
************************************************************************/
template<typename T>
int DoubleLinkedList<T>::NumItems()
{
	Node<T> * temp = m_head;
	int items = 0;
	while(temp != m_tail)
	{
		++items;
		temp = temp->m_next;
	}
	return ++items;
}

#endif