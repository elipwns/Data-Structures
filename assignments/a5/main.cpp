/***********************************************************
* Author:		eli kloft
* Lab Number:	a5
* Filename:		a5.cpp
* Date Created:	4/23/13
* Modifications:	
*
* Overview:
*	a wrapper around the double linked list class in the form of
*	an iterator.
*
* Input:
*	
*
* Output:
*	tests the various funcitons 
************************************************************/

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
using std::cout;

#include "AbstractIterator.h"
#include "doublelinkedlist.h"
#include "ListIterator.h"
#include "node.h"
#include "BackwardsIterator.h"
#include "ForwardIterator.h"
int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	DoubleLinkedList<int> * list = new DoubleLinkedList<int>();
	for(int i = 0; i < 8; ++i)
	{
		list->Append(i);
	}

	cout <<"Testing forwards\n";
	ForwardIterator<int> forward(*list);
	while(!forward.IsDone())
	{
		cout << forward.GetCurrent() << "\n";
		forward.MoveNext();
	}
	cout << forward.GetCurrent() << "\n";
	cout << "testing reset\n";
	forward.Reset();
	cout << forward.GetCurrent() << "\n";

	cout << "\n" << "Testing Backwards\n";
	BackwardsIterator<int> back(*list);
	while(!back.IsDone())
	{
		cout << back.GetCurrent() << "\n";
		back.MoveNext();
	}
	cout << back.GetCurrent() << "\n";
	cout <<"testing reset\n";
	back.Reset();
	cout << back.GetCurrent() << "\n";

	cout << "testing copy and op=" << "\n";
	ForwardIterator<int> copyForward(forward);
	cout << copyForward.GetCurrent() << " " << forward.GetCurrent() << "\n";

	system("Pause");
	delete list;
	return 0;
}