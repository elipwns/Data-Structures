/***********************************************************
* Author:		eli kloft
* Lab Number:	CST 211 Lab 5
* Filename:		Lab5.cpp 
* Date Created:	5/17/13
* Modifications:	5/21/13 fixed mem leaks
*
* Overview:
*	Directory Tree program
*
* Input:
*	path of folder from command line
*
* Output:
*	outputs all folders and files to a file called directory.txt
************************************************************/

#include "DirectoryTree.h"
#include <string>
using std::string;
#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	string Dir (argv[1]);
	
	cout << "Starting Directory: " << Dir << '\n';
	DirectoryTree Tree(Dir);
	
	DirectoryTree Copy(Tree);
	system("Pause");
	return 0;
}