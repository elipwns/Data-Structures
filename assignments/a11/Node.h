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

private:
	list<Edge<V>*> m_neighbors;
	bool m_processed;
	V m_data;
};

template<typename V>
Node<V>::Node(V data)
	:m_data(data), m_processed(false)
{
}

template<typename V>
Node<V>::~Node()
{
}

template<typename V>
Node<V>::Node(const Node<V> & that)
{
	*this = that;
}

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