/***********************************************************
* Author:		eli kloft
* Lab Number:	CST 211 Lab 6
* Filename:		Lab6.cpp
* Date Created:	
* Modifications:	
*
* Overview:
*	Applies Dijkstras Shortest path algorithm to the graph class
*
* Input:
*	2 cities
*
* Output:
*	distance, travel time, and path
************************************************************/

#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC
#include "edge.h"
#include "Graph.h"
#include "Node.h"
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::getline;
using std::string;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream;

void BuildGraph(Graph<string,string> & g1);
void Dijkstra(Graph<string,string> & g1);
bool addtolist(Node<string> * node, list<Node<string>*> & list);
void FindPath(string start, string end, vector<Node<string>*> pred, Graph<string,string> & g1);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Graph<string,string> g1;
	BuildGraph(g1);
	Dijkstra(g1);
	system("Pause");
	return 0;
}
/**********************************************************************	
* Purpose: to build the graph
*
* Entry: input from file
*
* Exit: closes the file
*
************************************************************************/

void BuildGraph(Graph<string,string> & g1)
{
	string ImpLine;
	ifstream infile("lab06.txt", std::ifstream::in);
	while (getline(infile, ImpLine, '\n'))  // Get each line
	{
	    // create a string stream from the standard string
	    istringstream StrLine(ImpLine);

	    string start, end, path, miles;

	    // Parse lines
	    getline(StrLine,start,',');
	    getline(StrLine,end,',');
	    getline(StrLine,path,',');
	    getline(StrLine,miles,',');   

		int m = atoi(miles.c_str());
		if(g1.DoesExist(start) && g1.DoesExist(end))
		{
			g1.InsertEdge(start, end, m, path);
		}
		else if(g1.DoesExist(start))
		{
			g1.Insert(end, start, m, path);
		}
		else if(g1.DoesExist(end))
		{
			g1.Insert(start, end, m, path);
		}
		else
		{
			g1.Insert(start);
			g1.Insert(end, start, m, path);
		}
	}
	infile.close();
}
/**********************************************************************	
* Purpose: does Dijkstars shortest path algorithm
*
* Entry: passed a graph by ref
*
* Exit: call find path
*
************************************************************************/

void Dijkstra(Graph<string,string> & g1)
{
	char buffer[256];
	
	string starting, ending;
	cout << "Start city: ";
	cin.rdbuf()->in_avail();
	cin.getline(buffer,256,'\n');
	starting = buffer;

	cout <<"\nEnd city: ";
	cin.rdbuf()->in_avail();
	cin.getline(buffer,256,'\n');
	ending = buffer;
	
	int * Distance = new int [g1.size_nodes()];
	int number = g1.size_nodes();
	vector<Node<string>*> Pred;
	Pred.resize(number);

	for(int i = 0; i < g1.size_nodes(); i++)
	{
		Distance[i] = -1;
		Pred[i] = nullptr;
	}

	//build the arrays....
	Distance[g1[starting]] = 0;
	
	Node<string> * node = g1.Index(g1[starting]);
	Node<string> * other_node (nullptr);
	list<Node<string>*> list, copy;
	
	bool change = true;
	while(g1.numberprocessed() < g1.size_nodes() && change)
	{
		node->setprocessed(true);
		if(addtolist(node, list))
		{
			while(!list.empty())
			{
				other_node = list.front();
				list.pop_front();

				//find distance and record
				Edge<string> * edge = g1.FindEdge(node, other_node);
				int weight = edge->getweight();
				int inttemp = Distance[g1[node->getdata()]] > 0 ? Distance[g1[node->getdata()]] : 0;
				if((Distance[g1[other_node->getdata()]] == -1) || (( weight + inttemp) < Distance[g1[other_node->getdata()]]))
				{
					Distance[g1[other_node->getdata()]] = weight + inttemp;
					Pred[g1[other_node->getdata()]] = node;
				}

				//update distance and pred arrays
			}
		}
		list.clear();
		Node<string> * save = nullptr, * current;
		copy = g1.listgetter();
		
		for(int i = 0; i < g1.size_nodes(); i++)
		{
			current = copy.front();
			copy.pop_front();
			if(save == nullptr && !current->getprocessed())
			{
				save = current;
			}
			else if(!current->getprocessed() && Distance[g1[current->getdata()]] != -1)
			{
				if(Distance[g1[current->getdata()]] < Distance[g1[save->getdata()]])
				{
					save = current;
				}
			}
		}
		node = save;
	}
	
	FindPath(starting, ending, Pred, g1);
	delete [] Distance;
}
/**********************************************************************	
* Purpose: adds a nodes neighbors to a list
*
* Entry: passed a node ptr and a list by ref
*
* Exit: returns true if list is not empty
*
************************************************************************/

bool addtolist(Node<string> * node, list<Node<string>*> & node_list)
{
	list<Edge<string>*> edge_list = node->neighborgetter();
	while(!edge_list.empty())
	{
		if(node == (edge_list.front())->aget())
		{
			if(!edge_list.front()->bget()->getprocessed())
				node_list.push_back(edge_list.front()->bget());
		}
		else if(node == edge_list.front()->bget())
		{
			if(!edge_list.front()->aget()->getprocessed())
				node_list.push_back(edge_list.front()->aget());
		}
		edge_list.pop_front();
	}
	if(node_list.empty())
		return false;
	else
		return true;
}
/**********************************************************************	
* Purpose: follows path from start node to end node
*
* Entry: passed 2 strings, a vector of node ptrs, and a graph by ref
*
* Exit: couts the route and time it would take
*
************************************************************************/

void FindPath(string start, string end, vector<Node<string>*> pred, Graph<string,string> & g1)
{
	cout << "\n Finding path from " << start << " to " << end;
	Node<string> * node1, * node2;
	node1 = g1.Index(g1[end]);
	node2 = pred[g1[end]];
	Edge<string> * edge1;
	
	float miles55(0.0f), miles65(0.0f);

	while(node2 != nullptr)
	{
		edge1 = g1.FindEdge(node1, node2);
		if(edge1->nameget() == "I-5")
			miles65 += edge1->getweight();
		else
			miles55 += edge1->getweight();
		cout << "\n";
		cout << "from " << node1->getdata();
		cout << " take " << edge1->nameget();
		cout << " to " << node2->getdata() << "\n";

		Node<string> * temp = node2;
		node1 = node2;
		node2 = pred[g1[temp->getdata()]];
	}
	float hrs = (miles55 / 55) + (miles65 / 65);
	float min;
	int temp;
	temp = hrs;
	min = hrs - static_cast<float>(temp);
	(min *= 60.0f) += 0.5f;
	int mins (static_cast<int>(min));
	int hr (static_cast<int>(hrs));
	cout << "\ntrip will take ";  
	
	cout << hr << " hour" << ((hr>1)?"s ":" ");
	
	cout <<((hr)?"and ":"") << mins << " min" << ((mins>1)?"s\n":"\n");
	cout <<"for a total of " << miles55 + miles65 << " miles\n";
}
