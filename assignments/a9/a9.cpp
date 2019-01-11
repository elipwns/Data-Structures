/***********************************************************
* Author:		eli kloft
* Lab Number:	a9
* Filename:		a9.cpp
* Date Created:	4/26/13
* Modifications:4/29/2013 finished up
*
* Overview:
*	wrapper around linked list to act as a que
*
* Input:
*	
* Output:
* tests the various functions
************************************************************/
#include <iostream>
using std::cout;
#include "doublelinkedlist.h"
#include "exception.h"
#include "node.h"
#include "que.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	Que<int> q1;
	try
	{
		q1.Dequeue();
	}
	catch(Exception any)
	{
		cout << any << "\n";
	}
	q1.Enqueue(1);
	q1.Enqueue(2);
	q1.Enqueue(3);

	cout << q1.Front() << "\n";
	q1.Front() = 5;
	cout << q1.Front() << "\n";

	cout << "Size of que: " << q1.Size() << "\n";

	if(!q1.isEmpty())
		cout << "List not empty";

	cout << q1.Dequeue() << "\n";
	cout << q1.Dequeue() << "\n";
	cout << q1.Dequeue() << "\n";
	if(!q1.isEmpty())
	{
		cout << q1.Dequeue() << "\n";
	}
	else
		cout << "list empty\n";

	return 0;
}