/***********************************************************
* Author:		eli kloft
* Lab Number:	a8
* Filename:		a8.cpp
* Date Created: 4/26/13
* Modifications:
*
* Overview:
*	this is a wrapper around the array to act as a circle que
*
* Input:
*	when creating the que pass it the size of you want it
*
* Output:
*	tests the various functions
************************************************************/

#include "array.h"
#include "exception.h"
#include "Que.h"
#include <iostream>
using std::cout;

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	Que<int> s1 (10);
	if(s1.isEmpty())
		cout << "Que is empty\n";
	try
	{
		s1.DeQue();
	}
	catch(Exception any)
	{
		cout << any << "\n";
	}
	for(int i = 1; i <= 10; ++i)
		s1.EnQue(i);
	if(s1.isFull()) // not catching
		cout << "Que is full\n";
	try
	{ 
		s1.EnQue(100);
	}
	catch(Exception any)
	{
		cout << any << "\n";
	}
	cout << "Deque: " << s1.DeQue() << "\n";
	cout << "Size: " << s1.Size() << "\n";
	cout << "Front: " << s1.Front() << "\n";
	s1.Front() = 5;
	cout << "Front: " << s1.Front() << "\n";
	s1.EnQue(100);
	cout << "Deque: " << s1.DeQue() << "\n";
	cout << "Deque: " << s1.DeQue() << "\n";
	cout << "Deque: " << s1.DeQue() << "\n";
	cout << "Deque: " << s1.DeQue() << "\n";
	cout << "Deque: " << s1.DeQue() << "\n";
	cout << "Deque: " << s1.DeQue() << "\n";
	cout << "Deque: " << s1.DeQue() << "\n";
	cout << "Deque: " << s1.DeQue() << "\n";
	cout << "Deque: " << s1.DeQue() << "\n";
	cout << "Deque: " << s1.DeQue() << "\n";

	try{
	cout << "Deque: " << s1.DeQue() << "\n";
	}
	catch (Exception any)
	{
		cout << any << "\n";
	}

	s1.EnQue(55);
	cout << s1.Front() << "\n";
	system("Pause");
	return 0;
}