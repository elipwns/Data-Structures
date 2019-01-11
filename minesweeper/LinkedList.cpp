#include "LinkedList.h"
/**********************************************************************	
* Purpose: 2 arg ctor for linked list
*
* Entry: passed two ints
*
* Exit: makes a new node with X,Y coord and sets head and tail to it
*
************************************************************************/

LinkedList::LinkedList(int x, int y)
{
	Node * head = new Node (x, y);
	m_head = head;
	m_tail = head;
}
/**********************************************************************	
* Purpose: linked list dtor
*
* Entry: 
*
* Exit: deletes the head node
*
************************************************************************/

LinkedList::~LinkedList()
{
	delete m_head;
}
/**********************************************************************	
* Purpose: linked list copy ctor
*
* Entry: passed a const linked list by ref
*
* Exit: copies the head and tail pointers
*
************************************************************************/

LinkedList::LinkedList(const LinkedList & copy)
{
	m_head = copy.m_head;
	m_tail = copy.m_tail;
}
/**********************************************************************	
* Purpose: overloaded operator =
*
* Entry:passed a const linked list by ref
*
* Exit: checks for self assignment and then copies over the pointers
*
************************************************************************/

LinkedList & LinkedList::operator=(const LinkedList & rhs)
{
	if (this != &rhs)
	{
		m_head = rhs.m_head;
		m_tail = rhs.m_tail;
	}
	return * this;
}
/**********************************************************************	
* Purpose: adds a node to the list
*
* Entry: passed two ints
*
* Exit: sets the ints to a new node and places the node into the que
*
************************************************************************/

void LinkedList::Add(int x, int y)
{
	Node * newNode = new Node(x,y);
	m_tail->m_next = newNode;
	m_tail = newNode;
}
/**********************************************************************	
* Purpose: advances the que
*
* Entry: 
*
* Exit:  moves the head pointer up one and deletes the old head node
*
************************************************************************/

void LinkedList::Next()
{
	Node * temp = m_head->m_next;
	delete m_head;
	m_head = temp;
}
/**********************************************************************	
* Purpose: getter for X
*
* Entry: 
*
* Exit: returns the int returned by nodes getter
*
************************************************************************/

int LinkedList::GetX()
{
	return m_head->GetX();
}
/**********************************************************************	
* Purpose: getter for Y
*
* Entry: 
*
* Exit: returns the int returned by nodes getter
*
************************************************************************/

int LinkedList::GetY()
{
	return m_head->GetY();
}