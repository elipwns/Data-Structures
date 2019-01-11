/************************************************************************
* Class: Node
*
* Purpose: holder for x,y and the next node in the list
*
* Manager functions:	
* 	Node ( )
* 		defaults to 0,0 and nullptr	
*	Node (int x, int y)
*		creates a node with x,y and nullptr for next
*	Node (const Node & copy)
*		copy constructor
*	operator = (const Node & copy)
*		overloaded operator =
*	~Node()
*		destructor
*	Getters for X,Y and the next pointer
*
* Methods:		
*		
*************************************************************************/

#ifndef NODE_H
#define NODE_H

class Node
{
	friend class LinkedList;
public:
	Node();
	Node(int x, int y);
	~Node();
	Node(const Node & copy);
	Node & operator=(const Node & in);
	int GetX();
	int GetY();
	Node * GetNext();

private:
	Node * m_next;
	Node * m_trail;
	int m_x;
	int m_y;
};

#endif
