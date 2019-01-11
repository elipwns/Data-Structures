/***********************************************************
* Author:		Eli kloft
* Lab Number:	CST 126 Lab 1
* Filename:		Lab1.cpp
* Date Created:	4/1/13
* Modifications: 4/2/13
*
* Overview:
*	this program is a demo of a safe 1-d array class with exceptions
*
* Input:
*	
*
* Output:
*	the program tests its own funcions and displays that to the screen
************************************************************/

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <string>
using std::string;
#include "array.h"
#include "exception.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	try
	{
	Array<int> test (5);
	cout << "testing get length " << test.GetLength() << endl;

	Array<char> testchar(3, -5);
	cout << "testing get start index " << testchar.GetStartIndex() << endl;

	Array<string> stringtest(4, 20);
	stringtest[20] = "\ntesting ";
	stringtest[21] = "code ";
	stringtest[22] = "errry ";
	stringtest[23] = "day\n\n";

	for (int i = 20; i < 24; i++)
		cout << stringtest[i];

	testchar[-5] = 'a';
	testchar[-4] = 'b';
	testchar[-3] = 'c';

	for (int i = 0; i < 5; i++)
		test[i] = i;
	for (int i = 0; i < 5; i++)
		cout << "testing overloaded brackets " << test[i] << endl;

	Array<int> copytest(test);
	for (int i = 0; i < 5; i++)
		cout << "copied test, now testing the copy " << copytest[i] << endl;

	Array<char>charcopytest = testchar;
	for (int i = -5; i < -2; i++)
		cout 
		<< "testing op = , using chars, and using negative starting values " 
		<< charcopytest[i] << endl;
	
	test.SetLength(7);
	for (int i = 0; i < 7; i++)
		cout << "testing setting a longer length " << test[i] << endl;

	test.SetLength(3);
	for(int i = 0; i < 3; i++)
		cout << "testing setting a shorter length " << test[i] << endl;

	cout << "testing bounds error checking\n";
	cout << charcopytest[10];
	}
	catch(bool except)
	{
		Exception test1("the exception test");
		Exception testexcept("There was an out-of-bounds Exception thrown");
		cout << testexcept << endl;
		Exception testTheTest(testexcept);
		cout << testTheTest << endl;
		Exception test2 = test1;
		cout << test2 << endl;		
	}
	system("Pause");
	return 0;
}