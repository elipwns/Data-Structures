/************************************************************************
* Class: LinkedList
*
* Purpose: This class manages the nodes in the Que
*
* Manager functions:	
*	LinkedList (int x, int y)
*		Creates a new node(x,y) and sets the head and tail to that node
*	LinkedList (const LinkedList & copy)
*		copy constructor
*	operator = (const LinkedList & copy)
*		overloaded operator =
*	~LinkedList()
*		destructor
*	Getters for X,Y
*
* Methods:		
*	void Add(int x, int y)
*		adds the x,y coord to a new node and sets tail = to that node
*	void Next()
*		deletes the node that head is pointing at and move the head to
*		the next node in the que
*************************************************************************/

#include "Node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
	friend class Board;
public:
	LinkedList(int x, int y);
	~LinkedList();
	LinkedList(const LinkedList & copy);
	LinkedList & operator=(const LinkedList & rhs);

	void Add(int x, int y);
	void Next();
	int GetX();
	int GetY();

private:
	Node * m_head;
	Node * m_tail;
};

#endif 