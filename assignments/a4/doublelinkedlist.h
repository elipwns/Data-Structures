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

	void PrintForwards();
	void PrintBackwards();

	Node<T> & getHead();
	Node<T> & getTail();
private:
	Node<T> * m_head;
	Node<T> * m_tail;
};


template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_head = new Node<T>();
	m_tail = m_head;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	if(m_head != nullptr)
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
}

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

template<typename T>
DoubleLinkedList<T> & DoubleLinkedList<T>::operator =(const DoubleLinkedList<T> & copy)
{
	if(this != &copy)
	{
		if(m_head->uninit)
			delete m_head;
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
					tempbefore->m_next = temp;
				}
				m_tail = temp;
				temp->m_next = nullptr;
			}
			else
				m_tail = m_head;
		}
	}
	return * this;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty()
{
	if(m_head == nullptr || m_head->uninit)
		return true;
	else
		return false;
}

template<typename T>
const T & DoubleLinkedList<T>::First()const
{
	if(m_head == nullptr || m_head->uninit)
		throw "No First";
	else
		return m_head->m_data;
}

template<typename T>
const T & DoubleLinkedList<T>::Last()const
{
	if(m_tail == nullptr || m_tail->uninit)
		throw "No Last";
	else
		return m_tail->m_data;
}

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

template<typename T>
Node<T> & DoubleLinkedList<T>::getHead()
{
	return *m_head;
}

template<typename T>
Node<T> & DoubleLinkedList<T>::getTail()
{
	return *m_tail;
}

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

#endif