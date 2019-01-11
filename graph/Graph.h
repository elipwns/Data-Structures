/************************************************************************
* Class: Graph
*
* Purpose: manages all the nodes and edges
*
* Manager functions:	
* 	Graph() - ctor
*	~Graph() - dtor
*	Graph(const Graph<V,E> &) - copy ctor
*	Graph<V,E> & operator=(const Graph<V,E> &) - op =
*
* Methods:		
*	int operator[](string s1) - search for data, return index
*	void Insert(V new_nodes_data) - insert node
*	void Insert(V new_nodes_data, V connected_to, int weight, E edge_name);
*	void InsertEdge(V node1, V node2, int weight, E edge_name) - insert edge
*	void Delete(V data) - delete node
*	void DeleteEdge(V node1, V node2) - delete edge
*	void DepthFirst() - traversal
*	void BreadthFirst() - traversal
*	bool DoesExist(V search) - finds if a node exists
*	void Reset() - resets processed flag
*	int size_nodes() - returns length of nodes
*	Node<V> * Index(int) - returns a node from a int index
*	Edge<E> * FindEdge(Node<V> * , Node<V> *) - returns edge between 2 nodes
*	list<Node<V>*> listgetter() - getter for list of nodes
*	int numberprocessed() - returns number of processed nodes in list
*************************************************************************/

#include "Node.h"
#include "edge.h"
#include <iostream>
using std::cout;
#include <list>
using std::list;
#include <string>
using std::string;

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
	int operator[](string s1);

	void Insert(V new_nodes_data);
	void Insert(V new_nodes_data, V connected_to, int weight, E edge_name);
	void InsertEdge(V node1, V node2, int weight, E edge_name);

	void Delete(V data);
	void DeleteEdge(V node1, V node2);

	void DepthFirst();
	void BreadthFirst();

	bool DoesExist(V search);

	void Reset();

	int size_nodes();

	Node<V> * Index(int);
	Edge<E> * FindEdge(Node<V> * , Node<V> *);
	list<Node<V>*> listgetter();
	int numberprocessed();
private:
	list<Node<V>*> m_All_Nodes;
	list<Edge<E>*> m_All_Edges;
};
/**********************************************************************	
* Purpose: return number of processed nodes
*
* Entry: 
*
* Exit: adds up all processed nodes and returns that number
*
************************************************************************/

template<typename V, typename E>
int Graph<V,E>::numberprocessed()
{
	int j = 0;
	Node<V> * ptr;
	list<Node<V>*> copy = m_All_Nodes;
	for(unsigned int i = 0; i < m_All_Nodes.size(); i++)
	{
		ptr = copy.front();
		copy.pop_front();
		if(ptr->getprocessed())
			j++;
	}
	return j;
}
/**********************************************************************	
* Purpose: getter for list of nodes
*
* Entry: 
*
* Exit: returns all nodes
*
************************************************************************/

template<typename V, typename E>
list<Node<V>*> Graph<V,E>::listgetter()
{
	return m_All_Nodes;
}
/**********************************************************************	
* Purpose: ctor
*
* Entry: 
*
* Exit: 
*
************************************************************************/

template<typename V, typename E>
Graph<V,E>::Graph()
{
}
/**********************************************************************	
* Purpose: dtor
*
* Entry:
*
* Exit: frees all memory
*
************************************************************************/

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
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a graph by const ref
*
* Exit: used op =
*
************************************************************************/
template<typename V, typename E>
Graph<V,E>::Graph(const Graph<V,E> & that)
{
	*this = that;
}
/**********************************************************************	
* Purpose: op =
*
* Entry: passed a graph by const ref
*
* Exit: creates new nodes and edges
*
************************************************************************/

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
/**********************************************************************	
* Purpose: inserts a node
*
* Entry: passed some data
*
* Exit: creates a new node
*
************************************************************************/

template<typename V, typename E>
void Graph<V,E>::Insert(V new_nodes_data)
{
	Node<V> * newnode = new Node<V>(new_nodes_data);
	m_All_Nodes.push_back(newnode);
}
/**********************************************************************	
* Purpose: inserts a node and edge
*
* Entry: passed two nodes, the weight and the name
*
* Exit: finds the node to connect to and adds a new node and edge
*
************************************************************************/

template<typename V, typename E>
void Graph<V,E>::Insert(V new_nodes_data, V connected_to, int weight, E edge_name)
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
		new_edge->m_name = edge_name;
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
/**********************************************************************	
* Purpose: inserts an edge between two nodes
*
* Entry: passed two nodes, the weight, and the name
*
* Exit: creates a new edge between the two nodes
*
************************************************************************/

template<typename V, typename E>
void Graph<V,E>::InsertEdge(V node1, V node2, int weight, E edge_name)
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
			newEdge->m_name = edge_name;
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
/**********************************************************************	
* Purpose: deletes a node
*
* Entry: passed some data
*
* Exit: finds the node, deletes it and all edges connecting to it
*
************************************************************************/

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
/**********************************************************************	
* Purpose: deletes edge between 2 nodes
*
* Entry: passed two nodes
*
* Exit: deletes the edge between the 2 nodes
*
************************************************************************/

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
/**********************************************************************	
* Purpose: prints graph
*
* Entry: 
*
* Exit: prints graph from bottom up
*
************************************************************************/

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
/**********************************************************************	
* Purpose: prints graph
*
* Entry: 
*
* Exit: prints graph from top down
*
************************************************************************/

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
/**********************************************************************	
* Purpose: resets nodes m_processed flag
*
* Entry: 
*
* Exit: sets all flags to false
*
************************************************************************/

template<typename V, typename E>
void Graph<V,E>::Reset()
{
	typename list<Node<V>*>::iterator it;
	
	for(it = m_All_Nodes.begin(); it != m_All_Nodes.end(); it++)
	{
		(*it)->m_processed = false;
	}

}
/**********************************************************************	
* Purpose: returns true if node is found
*
* Entry: passed a search item
*
* Exit: searches for item. returns true if found
*
************************************************************************/

template<typename V, typename E>
bool Graph<V,E>::DoesExist(V search)
{
	bool found = false;
	list<Node<V>*> copy = m_All_Nodes;
	while(!copy.empty() && !found)
	{
		Node<V> * ptr = copy.front();
		copy.pop_front();
		if(ptr->m_data == search)
			found = true;
	}
	return found;
}
/**********************************************************************	
* Purpose: returns size of list of nodes
*
* Entry: 
*
* Exit: returns all nodes size
*
************************************************************************/

template<typename V, typename E>
int Graph<V,E>::size_nodes()
{
	return m_All_Nodes.size();
}
/**********************************************************************	
* Purpose: overloaded operator []
*
* Entry: passed a string
*
* Exit: returns the offset of the particular node
*
************************************************************************/

template<typename V, typename E>
int Graph<V,E>::operator[](string search)
{
	list<Node<V>*> copy = m_All_Nodes;
	bool found = false;
	int i = 0;
	while(!found && !copy.empty())
	{
		Node<V> * node = copy.front();
		copy.pop_front();
		if(node->m_data == search)
		{
			found = true;
		}
		else
			i++;
	}
	if(1)
		return((found)? i:-1);

}
/**********************************************************************	
* Purpose: returns node from an index
*
* Entry: passed the index wanted
*
* Exit: returns the node
*
************************************************************************/

template<typename V, typename E>
Node<V> * Graph<V,E>::Index(int j)
{
	list<Node<V>*> copy = m_All_Nodes;
	for(int i = 0; i < j; i++)
	{
		copy.pop_front();
	}
	return copy.front();
}
/**********************************************************************	
* Purpose: finds an edge between 2 nodes
*
* Entry: passed two nodes
*
* Exit: returns the edge between the two nodes
*
************************************************************************/

template<typename V, typename E>
Edge<E> * Graph<V,E>::FindEdge(Node<V> * a, Node<V> * b)
{
	list<Edge<E>*> copy = m_All_Edges;
	Edge<E> * edge;
	bool found = false;
	while(!copy.empty() && !found)
	{
		edge = copy.front();
		copy.pop_front();
		if((edge->aget() == a && edge->bget() == b) || edge->aget() == b && edge->bget() == a)
		{
			found = true;
		}
	}
	if(found)
		return edge;
	else
		return nullptr;
}

#endif