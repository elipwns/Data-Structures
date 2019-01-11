#include <iostream>
using std::ostream;

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
	template <typename T> friend class DoubleLinkedList;
	template <typename T> friend ostream & operator <<(ostream & stream, Node<T> & n1);
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
	T getData();
};

template<typename T>
ostream & operator <<(ostream & stream, Node<T> & n1)
{
	if (&n1 == nullptr)
		return stream << "Not Initialized";
	return stream << n1.getData();
}

template<typename T>
Node<T>::Node()
	:m_data(T()), m_next(nullptr), m_prev(nullptr), uninit(true)
{
}

template<typename T>
Node<T>::Node(T data)
	:m_data(data), m_next(nullptr), m_prev(nullptr), uninit(false)
{
}

template<typename T>
Node<T>::~Node()
{
	m_data = 0;
	m_next = nullptr;
	m_prev = nullptr;
	uninit = true;
}

template<typename T>
Node<T>::Node(const Node & copy)
{
	m_data = copy.m_data;
	m_next = copy.m_next;
	m_prev = copy.m_prev;
	uninit = copy.uninit;
}

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

template<typename T>
T Node<T>::getData()
{
	return m_data;
}


#endif