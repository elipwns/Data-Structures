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
private:
	int m_weight;
	Node<E> * A;
	Node<E> * B;
};

template<typename E>
Edge<E>::Edge()
	:A(nullptr), B(nullptr), m_weight(0)
{
}

template<typename E>
Edge<E>::~Edge()
{
}

template<typename E>
Edge<E>::Edge(const Edge<E> & that)
{
	*this = that;
}

template<typename E>
Edge<E> & Edge<E>::operator=(const Edge<E> & rhs)
{
	if(*this != rhs)
	{
		A = rhs.A;
		B = rhs.B;
		m_weight = rhs.m_weight;
	}
	return * this;
}

#endif