/************************************************************************
* Class: node
*
* Purpose: holds the data and the nodes neighbors
*
* Manager functions:	
* 	Node(V data) - ctor, passed data
*	~Node() - dtor
*	Node(const Node<V> &) - copy ctor
*	Node<V> & operator=(const Node<V> &) - op =
*
* Methods:	
*	Getters:
*	list<Edge<V>*> neighborgetter();
*	bool getprocessed();
*	V getdata();
*	Setters:
*	void setprocessed(bool);
*************************************************************************/

#include <list>
using std::list;
#include "edge.h"


#ifndef NODE_H
#define NODE_H

template<typename V>
class Node
{
	template<typename V, typename E>
	friend class Graph;
public:
	Node(V data);
	~Node();
	Node(const Node<V> &);
	Node<V> & operator=(const Node<V> &);

	list<Edge<V>*> neighborgetter();
	bool getprocessed();
	void setprocessed(bool);
	V getdata();
private:
	list<Edge<V>*> m_neighbors;
	bool m_processed;
	V m_data;
};
/**********************************************************************	
* Purpose: getter for data
*
* Entry: 
*
* Exit: returns data
*
************************************************************************/

template<typename V>
V Node<V>::getdata()
{
	return m_data;
}
/**********************************************************************	
* Purpose: set processed
*
* Entry: passed a bool
*
* Exit: sets processed to parameter
*
************************************************************************/

template<typename V>
void Node<V>::setprocessed(bool a)
{
	 m_processed = a;
}
/**********************************************************************	
* Purpose: getter for processed
*
* Entry: 
*
* Exit: returns m_processed
*
************************************************************************/

template<typename V>
bool Node<V>::getprocessed()
{
	return m_processed;
}
/**********************************************************************	
* Purpose: getter for neighbors
*
* Entry: 
*
* Exit: returns neighbors
************************************************************************/

template<typename V>
list<Edge<V>*> Node<V>::neighborgetter()
{
	return m_neighbors;
}
/**********************************************************************	
* Purpose: node 1 arg ctor
*
* Entry: passed a V data
*
* Exit: sets up data , set m_processed to false
*
************************************************************************/

template<typename V>
Node<V>::Node(V data)
	:m_data(data), m_processed(false)
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

template<typename V>
Node<V>::~Node()
{
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a node by const ref
*
* Exit: uses op =
*
************************************************************************/

template<typename V>
Node<V>::Node(const Node<V> & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: op =
*
* Entry: passed a node by const ref
*
* Exit: copies the data
*
************************************************************************/

template<typename V>
Node<V> & Node<V>::operator=(const Node<V> & rhs)
{
	if(*this != rhs)
	{
		m_data = rhs.m_data;
		m_neighbors = rhs.m_neighbors;
		m_processed = rhs.m_processed;
	}
	return * this;
}


#endif