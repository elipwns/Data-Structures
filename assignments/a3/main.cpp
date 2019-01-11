/***********************************************************
* Author:		Eli kloft
* Lab Number:	CST 126 Lab3
* Filename:		Lab3.cpp
* Date Created:	4/4/13
* Modifications: 4/6/13
*
* Overview:
*	this program is a demo of a safe 2-d array class with exceptions
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

//#include "array.h"
#include "array2d.h"
#include "exception.h"
#include "Row.h"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	try{
	Array2d<int> test(3,3);
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			test[i][j] = i + j;

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cout << "testing putting in numbers and retrieving them..."
			<< test[i][j] << endl;

	Array2d<int> test2 = test;

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cout << "testing the op =..." << test2[i][j] << endl;

	cout << "testing get row.." << test.getRow() << endl;
	cout << "testing get col.." << test.getColumn() << endl;

	test.setColumn(4); 
	cout << "testing get col after resize.." << test.getColumn() << endl;

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 4; j++)
			cout << "testing the col resize ..." << test[i][j] << endl;

	test.setRow(4);
	cout << "testing get row after resize.." << test.getRow() << endl;

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			cout << "testing the row resize ..." << test[i][j] << endl;

	Array2d<string> stringtest(2,2);
	stringtest[0][0] = "first";
	stringtest[0][1] = "second";
	stringtest[1][0] = "third";
	stringtest[1][1] = "fourth";

	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			cout << stringtest[i][j] << endl;

	const Array2d<int> test3(1,1);
	cout << "testing const.." << test3[0][0] << endl;

	cout << "testing exceptions" << endl;
	test2[5][1] = 2;
	Array2d<int>(-1,0); //exception but wont be reached bcuz of line above
	}
	catch(Exception any)
	{
		cout << any << endl;
	}
	return 0;
}