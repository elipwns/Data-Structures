/***********************************************************
* Author:		eli kloft
* Lab Number:	a7
* Filename:		a7.cpp
* Date Created:	4/23/13
* Modifications:	
*
* Overview:
*	this is a wrapper around a linked list to act as a stack
*
* Input:
*	
* Output:
*	tests the various functions 
************************************************************/

#include "Stack.h"
#include "exception.h"
#include "doublelinkedlist.h"

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	Stack<int> s1;
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
	
	cout << "Peek: " << s1.Peek() << "\n";
	cout << "Pop: " << s1.Pop() << "\n";
	cout << "Peek: " << s1.Peek() << "\n";
	cout << "Size: " << s1.Size() << "\n";
	system("Pause");
	
	return 0;
}

