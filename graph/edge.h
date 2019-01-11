/************************************************************************
* Class: edge
*
* Purpose: the road between 2 cities
*
* Manager functions:	
* 	Edge() - ctor
*	~Edge() - dtor
*	Edge(const Edge<E> &) - copy ctor
*	Edge<E> & operator=(const Edge<E> &) - op =
*
* Getters:		
*	Node<E> * aget();
*	Node<E> * bget();
*	int getweight();
*	E nameget();
*************************************************************************/

template<typename E>
class Node;

#ifndef EDGE_H
#define EDGE_H

template<typename E>
class Edge
{
	template<typename V, typename E>
	friend class Graph;
public:
	Edge();
	~Edge();
	Edge(const Edge<E> &);
	Edge<E> & operator=(const Edge<E> &);

	Node<E> * aget();
	Node<E> * bget();
	int getweight();
	E nameget();
private:
	E m_name;
	int m_weight;
	Node<E> * A;
	Node<E> * B;
};
/**********************************************************************	
* Purpose: name getter
*
* Entry: 
*
* Exit: returns the name
*
************************************************************************/

template<typename E>
E Edge<E>::nameget()
{
	return m_name;
}

/**********************************************************************	
* Purpose: weight getter
*
* Entry: 
*
* Exit: returns the weight
*
************************************************************************/

template<typename E>
int Edge<E>::getweight()
{
	return m_weight;
}
/**********************************************************************	
* Purpose: a getter
*
* Entry: 
*
* Exit: returns node A
************************************************************************/

template<typename E>
Node<E> * Edge<E>::aget()
{
	return A;
}
/**********************************************************************	
* Purpose: b getter
*
* Entry: 
*
* Exit: returns node B
************************************************************************/

template<typename E>
Node<E> * Edge<E>::bget()
{
	return B;
}
/**********************************************************************	
* Purpose: edge ctor
*
* Entry: 
*
* Exit: sets a and b to nullptr and weight to 0
*
************************************************************************/

template<typename E>
Edge<E>::Edge()
	:A(nullptr), B(nullptr), m_weight(0)
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

template<typename E>
Edge<E>::~Edge()
{
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a edge by const ref
*
* Exit: uses op =
*
************************************************************************/

template<typename E>
Edge<E>::Edge(const Edge<E> & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: op =
*
* Entry: passed an edge by const ref
*
* Exit: copies over the data
*
************************************************************************/

template<typename E>
Edge<E> & Edge<E>::operator=(const Edge<E> & rhs)
{
	if(*this != rhs)
	{
		A = rhs.A;
		B = rhs.B;
		m_weight = rhs.m_weight;
		m_name = rhs.m_name;
	}
	return * this;
}

#endif