#include <iostream>
using std::cout;
using std::endl;
#include <queue>
using std::queue;
#ifndef BST_H
#define BST_H

template<typename T>
class BST
{
public:
	BST(T data);
	~BST();
	BST(const BST<T> &);
	BST<T> & operator =(const BST<T> &);

	void Insert(T data);
	void Delete(T search_data, BST<T> * parent);
	void Purge(BST<T> * test);
	int Height();
	void In_Order();
	void Pre_Order();
	void Post_Order();
	void Breadth_First(queue<BST<T>> & q1);
	void FindLowest(BST<T> * Start, BST<T> * Parent, BST<T> * ROP);
	void Swap(BST<T> * Start);
	
private:
	BST<T> * m_left;
	BST<T> * m_right;
	T m_data;
	int m_height;
};

template<typename T>
BST<T>::BST(T data)
	:m_data(data), m_left(nullptr), m_right(nullptr), m_height(0)
{
}

template<typename T>
BST<T>::~BST()
{

}

template<typename T>
BST<T>::BST(const BST<T> & that)
{
	*this = that;
}

template<typename T>
BST<T> & BST<T>::operator =(const BST<T> & rhs)
{
	m_data = rhs.m_data;
	m_left = rhs.m_left;
	m_right = rhs.m_right;
	m_height = rhs.m_height;
	return * this;
}

template<typename T>
void BST<T>::Insert(T data)
{
	if(data <= m_data)
	{
		if(m_left != nullptr)
			m_left->Insert(data);
		else
			m_left = new BST<T>(data);
	}
	if(data > m_data)
	{
		if(m_right != nullptr)
			m_right->Insert(data);
		else
			m_right = new BST<T>(data);
	}
}

template<typename T>
void BST<T>::Delete(T search_data, BST<T> * parent)
{
	if(search_data == m_data)
	{
		if(m_left == nullptr && m_right == nullptr)
		{
			if(parent->m_left = this)
				parent->m_left = nullptr;
			if(parent->m_right = this)
				parent->m_right = nullptr;
			delete this;
		}
		else if(m_left == nullptr)
		{
			if(this == parent->m_right)
				parent->m_right = m_right;
			else if(this == parent->m_left)
				parent->m_left = m_right;
			delete this;
		}
		else if(m_right == nullptr)
		{
			if(this == parent->m_left)
				parent->m_left = m_left;
			else if(this == parent->m_right)
				parent->m_right = m_left;
			delete this;
		}
		else
		{
			Swap(this);
		}
	}
	else
	{
		if(m_left != nullptr)
			m_left->Delete(search_data, this);
		if(m_right != nullptr)
			m_right->Delete(search_data, this);
	}
}

template<typename T>
void BST<T>::Purge(BST<T> * test)
{
	if(m_left != nullptr)
		m_left->Purge(m_left);
	if(m_right != nullptr)
		m_right->Purge(m_right);
	if (this != nullptr)
		delete test;
}

template<typename T>
int BST<T>::Height()
{
	queue<BST<T>> q1;
	BST<T> last(0);
	m_height = 0;
	
	q1.push(*this);
	while(!q1.empty())
	{
		last = q1.front();
		q1.pop();
		if(last.m_left != nullptr)
		{
			last.m_left->m_height = last.m_height + 1;
			q1.push(*last.m_left);
		}
		if(last.m_right != nullptr)
		{
			last.m_right->m_height = last.m_height + 1;
			q1.push(*last.m_right);
		}
	}
	return last.m_height;
}

template<typename T>
void BST<T>::In_Order()
{
	if(m_left != nullptr)
		m_left->In_Order();
	cout << m_data << endl;
	if(m_right != nullptr)
		m_right->In_Order();
}

template<typename T>
void BST<T>::Pre_Order()
{
	cout << m_data << endl;
	if(m_left != nullptr)
		m_left->Pre_Order();
	if(m_right != nullptr)
		m_right->Pre_Order();
}

template<typename T>
void BST<T>::Post_Order()
{
	if(m_left != nullptr)
		m_left->Post_Order();
	if(m_right != nullptr)
		m_right->Post_Order();
	cout << m_data << endl;
}

template<typename T>
void BST<T>::Breadth_First(queue<BST<T>> & q1)
{
	cout << m_data << endl;
	if(m_left != nullptr)
		q1.push(*m_left);
	if(m_right != nullptr)
		q1.push(*m_right);
	while(!q1.empty())
	{
		BST<T> temp = q1.front();
		q1.pop();
		temp.Breadth_First(q1);
	}
}

template<typename T>
void BST<T>::Swap(BST<T> * Start)
{
	FindLowest(Start->m_right, Start, Start);
}

template<typename T>
void BST<T>::FindLowest(BST<T> * Start, BST<T> * Parent, BST<T> * ROP)
{
	while(Start->m_left != nullptr)
	{
		Parent = Start;
		Start = Start->m_left;
	}
	
	Parent->m_left = nullptr;
	ROP->m_data = Start->m_data;
	delete Start;
}
#endif
