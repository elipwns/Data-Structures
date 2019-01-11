/***********************************************************
* Author:		eli kloft
* Lab Number:	a6
* Filename:		a6.cpp
* Date Created:	4/23/13
* Modifications:
*
* Overview:
*	this is a wrapper around the array class that serves as a stack
*
* Input:
*
* Output:
*	tests the various functions
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "array.h"
#include "exception.h"
#include "stack.h"
#include <iostream>
using std::cout;

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	Stack<int> s1 (10);
	if(s1.isEmpty())
		cout << "Stack is empty\n";
	try
	{
		s1.Pop();
	}
	catch(Exception any)
	{
		cout << any << "\n";
	}
	for(int i = 0; i < 10; ++i)
		s1.Push(i);
	if(s1.isFull())
		cout << "Stack is full\n";
	try
	{ 
		s1.Push(100);
	}
	catch(Exception any)
	{
		cout << any << "\n";
	}
	cout << "Peek: " << s1.Peek() << "\n";
	cout << "Pop: " << s1.Pop() << "\n";
	cout << "Peek: " << s1.Peek() << "\n";
	cout << "Size: " << s1.Size() << "\n";
	system("Pause");
	
	return 0;
}