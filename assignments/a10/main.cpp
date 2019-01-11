#include "BST.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	BST<int> top(10);
	top.Insert(8);
	top.Insert(12);
	top.Insert(7);
	top.Insert(9);
	top.Insert(11);
	top.Insert(13);
	top.Insert(14);
	top.Insert(1);

	int temp = 0;
	temp = top.Height();
	cout << "height = " << temp << endl;

	cout << "post order\n";
	top.Post_Order();
	cout << endl;

	cout << "In order\n";
	top.In_Order();
	cout << endl;

	cout << "Pre order\n";
	top.Pre_Order();
	cout << endl;

	cout << "Breadth first\n";
	queue<BST<int>> q1;
	top.Breadth_First(q1);
	cout << endl;

	cout << "Showing delete a leaf(1), delete a node with 1 child(13), and delete a node with 2 childre(10)\n";
	top.Delete(1, nullptr);
	top.Delete(13, nullptr);
	top.Delete(10, nullptr);
	queue<BST<int>> q2;
	top.Breadth_First(q2);
	cout << endl;

	temp = top.Height();
	cout << "height = " << temp << endl;
	cout << "testing purge\n";
	top.Purge(nullptr);
	system("Pause");
	return 0;
}