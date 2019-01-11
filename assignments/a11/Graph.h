#include "Node.h"
#include "edge.h"
#include <iostream>
using std::cout;
#include <list>
using std::list;

#ifndef GRAPH_H
#define GRAPH_H

template<typename V, typename E>
class Graph
{
public:
	Graph();
	~Graph();
	Graph(const Graph<V,E> &);
	Graph<V,E> & operator=(const Graph<V,E> &);

	void Insert(V new_nodes_data);
	void Insert(V new_nodes_data, V connected_to, E weight);
	void InsertEdge(V node1, V node2, E weight);

	void Delete(V data);
	void DeleteEdge(V node1, V node2);

	void DepthFirst();
	void BreadthFirst();

	void Reset();
private:
	list<Node<V>*> m_All_Nodes;
	list<Edge<E>*> m_All_Edges;
};

template<typename V, typename E>
Graph<V,E>::Graph()
{
}

template<typename V, typename E>
Graph<V,E>::~Graph()
{
	while(!m_All_Edges.empty())
	{
		Edge<E> * temp = m_All_Edges.back();
		m_All_Edges.pop_back();
		delete temp;
	}
	while(!m_All_Nodes.empty())
	{
		Node<V> * temp2 = m_All_Nodes.back();
		m_All_Nodes.pop_back();
		delete temp2;
	}
}

template<typename V, typename E>
Graph<V,E>::Graph(const Graph<V,E> & that)
{
	*this = that;
}

template<typename V, typename E>
Graph<V,E> & Graph<V,E>::operator=(const Graph<V,E> & rhs)
{
	//if (*this != rhs)
	//{
		while(!m_All_Edges.empty())
		{
			Edge<E> * temp = m_All_Edges.back();
			m_All_Edges.pop_back();
			delete temp;
		}
		while(!m_All_Nodes.empty())
		{
			Node<V> * temp2 = m_All_Nodes.back();
			m_All_Nodes.pop_back();
			delete temp2;
		}
		list<Edge<E>*> edgecpy = rhs.m_All_Edges;
		list<Node<V>*> nodecpy = rhs.m_All_Nodes;
		while(!nodecpy.empty())
		{
			Node<V> * t1 = nodecpy.front();
			Insert(t1->m_data);
			nodecpy.pop_front();
		}
		while(!edgecpy.empty())
		{
			Edge<E> * e1 = edgecpy.front();
			InsertEdge(e1->A->m_data, e1->B->m_data, e1->m_weight);
			edgecpy.pop_front();
		}

//	}
	return * this;
}

template<typename V, typename E>
void Graph<V,E>::Insert(V new_nodes_data)
{
	Node<V> * newnode = new Node<V>(new_nodes_data);
	m_All_Nodes.push_back(newnode);
}

template<typename V, typename E>
void Graph<V,E>::Insert(V new_nodes_data, V connected_to, E weight)
{
	Node<V> * newnode = new Node<V>(new_nodes_data);
	m_All_Nodes.push_back(newnode);

	list<Node<V>*> copy = m_All_Nodes;
	Node<V> * oldnode = nullptr;
	if(!copy.empty())
		oldnode = copy.back();
	while(oldnode->m_data != connected_to && !copy.empty())
	{
		copy.pop_back();
		oldnode = copy.back();
	}
	if(oldnode->m_data == connected_to)
	{
		Edge<E> * new_edge = new Edge<E>;
		new_edge->A = newnode;
		new_edge->B = oldnode;
		new_edge->m_weight = weight;
		m_All_Edges.push_back(new_edge);

		newnode->m_neighbors.push_back(new_edge);
		oldnode->m_neighbors.push_back(new_edge);
	}
	else
		cout << "\nCould not find node to connect to!\n";
}

template<typename V, typename E>
void Graph<V,E>::InsertEdge(V node1, V node2, E weight)
{
	list<Node<V>*> copy = m_All_Nodes;
	Node<V> * node_1 = nullptr;
	if(!copy.empty())
		node_1 = copy.back();
	while(node_1->m_data != node1 && !copy.empty())
	{
		copy.pop_back();
		node_1 = copy.back();
	}
	if(node_1->m_data == node1)
	{
		copy = m_All_Nodes;
		Node<V> * node_2 = nullptr;
		if(!copy.empty())
			node_2 = copy.back();
		while(node_2->m_data != node2 && !copy.empty())
		{
			copy.pop_back();
			node_2 = copy.back();
		}
		if(node_2->m_data == node2)
		{
			Edge<E> * newEdge = new Edge<E>;
			m_All_Edges.push_back(newEdge);
			newEdge->m_weight = weight;
			newEdge->A = node_1;
			newEdge->B = node_2;

			node_1->m_neighbors.push_back(newEdge);
			node_2->m_neighbors.push_back(newEdge);
		}
		else
			cout << "\nCould not find the nodes to add an edge to!\n";
	}
	else
		cout << "\nCould not find the nodes to add an edge to!\n";
}

template<typename V, typename E>
void Graph<V,E>::Delete(V data)
{
	list<Edge<E>*> copy2 = m_All_Edges;
	Edge<E> * edge = nullptr;
	if(!copy2.empty())
		edge = copy2.back();
	while(!copy2.empty())
	{
		copy2.pop_back();
		if(edge->A->m_data == data || edge->B->m_data == data)
		{
			m_All_Edges.remove(edge);
			delete edge;
		}
		if(!copy2.empty())
			edge = copy2.back();
	}


	list<Node<V>*> copy = m_All_Nodes;
	Node<V> * node1 = nullptr;
	if(!copy.empty())
		node1 = copy.back();
	while(node1->m_data != data && !copy.empty())
	{
		copy.pop_back();
		node1 = copy.back();
	}
	if(node1->m_data == data)
	{
		m_All_Nodes.remove(node1);
		delete node1;
	}
	else
		cout << "\ncould not find node to delete!\n";
}

template<typename V, typename E>
void Graph<V,E>::DeleteEdge(V node1, V node2)
{
	bool found = false;
	list<Edge<E>*> copy2 = m_All_Edges;
	Edge<E> * edge = nullptr;
	if(!copy2.empty())
		edge = copy2.back();
	while(!copy2.empty() && !found)
	{
		copy2.pop_back();
		if((edge->A->m_data == node1 && edge->B->m_data == node2) || (edge->A->m_data == node2 && edge->B->m_data == node1))
		{
			m_All_Edges.remove(edge);
			delete edge;
			found = true;
		}
		if(!copy2.empty())
			edge = copy2.back();
	}
	if(!found)
		cout << "\nCould not find edge between those two nodes!\n";
}

template<typename V, typename E>
void Graph<V,E>::DepthFirst()
{
	list<Node<V>*> temp = m_All_Nodes;
	list<Node<V>*> l1;
	Node<V> * a_node;
	l1.push_front(temp.front());
	while(!l1.empty())
	{
		a_node = l1.front();
		l1.pop_front();
		a_node->m_processed = true;
		cout << a_node->m_data << "\n";
		while(!a_node->m_neighbors.empty())
		{
			Edge<E> * temp1 = a_node->m_neighbors.front();
			Node<V> * temp2 = ((temp1->A == a_node) ? temp1->B : temp1->A);
			if(!temp2->m_processed)
				l1.push_front(temp2);
			a_node->m_neighbors.pop_front();
		}
	}
}

template<typename V, typename E>
void Graph<V,E>::BreadthFirst()
{
	list<Node<V>*> l1;
	list<Node<V>*> copy = m_All_Nodes;
	Node<V> * a_node;

	l1.push_back(copy.front());
	copy.pop_front();
	while(!l1.empty())
	{
		a_node = l1.front();
		l1.pop_front();
		a_node->m_processed = true;
		cout << a_node->m_data << "\n";
		while(!a_node->m_neighbors.empty())
		{
			Edge<E> * temp1 = a_node->m_neighbors.front();
			Node<V> * temp2 = ((temp1->A == a_node) ? temp1->B : temp1->A);
			if(!temp2->m_processed)
				l1.push_back(temp2);
			a_node->m_neighbors.pop_front();
		}
	}
}

template<typename V, typename E>
void Graph<V,E>::Reset()
{
	typename list<Node<V>*>::iterator it;
	
	for(it = m_All_Nodes.begin(); it != m_All_Nodes.end(); it++)
	{
		(*it)->m_processed = false;
	}

}

#endif