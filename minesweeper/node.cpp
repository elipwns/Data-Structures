#include "Node.h"
/**********************************************************************	
* Purpose: node no arg ctor
*
* Entry: 
*
* Exit: defaults to 0,0 and no next pointer
*
************************************************************************/

Node::Node()
	:m_x(0), m_y(0), m_next(nullptr)
{
}
/**********************************************************************	
* Purpose: node 2 arg ctor
*
* Entry: passed two ints
*
* Exit: sets the X,Y to the ints and the next pointer to null
*
************************************************************************/

Node::Node(int x, int y)
	:m_x(x), m_y(y), m_next(nullptr)
{
}
/**********************************************************************	
* Purpose: node dtor
*
* Entry: 
*
* Exit: 
*
************************************************************************/

Node::~Node()
{
}
/**********************************************************************	
* Purpose: node copy ctor
*
* Entry: passed a const node by ref
*
* Exit: copies the data elements
*
************************************************************************/

Node::Node(const Node & copy)
{
	m_next = copy.m_next;
	m_trail = copy.m_trail;
	m_x = copy.m_x;
	m_y = copy.m_y;
}
/**********************************************************************	
* Purpose: overloade operator = for node
*
* Entry: passed a const node by ref
*
* Exit: checks for self assignment then copies over the data
*
************************************************************************/

Node & Node::operator=(const Node & in)
{
	if (this != &in)
	{
		m_next = in.m_next;
		m_trail = in.m_trail;
		m_x = in.m_x;
		m_y = in.m_y;
	}
	return * this;
}
/**********************************************************************	
* Purpose: getter for x
*
* Entry: 
*
* Exit: returns x
*
************************************************************************/

int Node::GetX()
{
	return m_x;
}
/**********************************************************************	
* Purpose: getter for y
*
* Entry: 
*
* Exit: returns y
************************************************************************/

int Node::GetY()
{
	return m_y;
}
/**********************************************************************	
* Purpose: getter for next pointer
*
* Entry:
*
* Exit: returns the next pointer
*
************************************************************************/

Node * Node::GetNext()
{
	return m_next;
}
