#include "Graph.h"
#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Graph<int, int> g1, g2;
	g1.Insert(5);
	g1.Insert(10, 5, 5);
	g1.Insert(7);
	g1.InsertEdge(5, 7, 2);

	g1.DepthFirst(); //traversal
	g1.Reset();

	g2 = g1; //test op =

	//deletes the node and all edges connected to him
	g1.Delete(5);
	g1.DeleteEdge(5, 7); //cant cuz already deleted

	g2.BreadthFirst(); //testing op= and traversal
	system("Pause");
	return 0;
}