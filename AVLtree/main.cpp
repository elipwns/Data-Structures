/***********************************************************
* Author:		eli kloft
* Lab Number:	CST 211 Lab 4
* Filename:		Lab4.cpp
* Date Created:	5/16/13
* Modifications:	
*
* Overview:
*	AVL Tree
*
* Input:
*	Data From Slides in Class!
*
* Output:
*	Outputs when doing rotations, and which was done.
*	Deletes nodes and shows outputs the new tree
************************************************************/
#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC
#include "avltree.h"
using std::endl;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	avltree<int> avl1;
	AVLNode<int> * node = nullptr;
	bool h;
	
	node = avl1.insert(8, &h);
	avl1.setroot(node);

	node = avl1.insert(9, &h);
	avl1.setroot(node);

	node = avl1.insert(10, &h);
	avl1.setroot(node);

	node = avl1.insert(2, &h);
	avl1.setroot(node);

	node = avl1.insert(1, &h);
	avl1.setroot(node);

	node = avl1.insert(5, &h);
	avl1.setroot(node);

	node = avl1.insert(3, &h);
	avl1.setroot(node);

	node = avl1.insert(6, &h);
	avl1.setroot(node);

	node = avl1.insert(4, &h);
	avl1.setroot(node);

	node = avl1.insert(7, &h);
	avl1.setroot(node);

	node = avl1.insert(11, &h);
	avl1.setroot(node);


	cout << endl << "tree:\n";
	avl1.display(node);

	node = avl1.deldata(node, 8, &h);
	avl1.setroot(node);
	node = avl1.deldata(node, 5, &h);
	avl1.setroot(node);

	cout << endl << "tree after delete (nodes 8 and 5):\n";
	avl1.display(node);
	cout << endl;

	system("Pause");
	return 0;
}