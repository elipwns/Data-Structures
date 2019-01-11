/************************************************************************
* Class: directory tree
*
* Purpose: contains the first folder and its childrens
*
* Manager functions:	
* 	DirectoryTree(const string & path) - ctor, passed a string by const ref
*	DirectoryTree(const DirectoryTree & cpy) - copy ctor
*	DirectoryTree & operator=(const DirectoryTree & rhs) - op =
*	~DirectoryTree() - dtor
*
* Methods:		
**************************************************************************/
#ifndef DIRECTORY_TREE_H
#define DIRECTORY_TREE_H

#include <Windows.h>
#include "doublelinkedlist.h"
#include <string>
#include <fstream>
using std::ofstream;
using std::string;

class DirectoryTree
{
public:
	DirectoryTree(const string & path);
	DirectoryTree(const DirectoryTree & cpy);
	DirectoryTree & operator=(const DirectoryTree & rhs);
	~DirectoryTree();
private:
	string m_Path;
	DoubleLinkedList<DirectoryTree*> m_Children;
};
/**********************************************************************	
* Purpose: 1 arg ctor
*
* Entry: passed a string by const ref
*
* Exit: adds all the files and folders to the linked list
*
************************************************************************/
DirectoryTree::DirectoryTree(const string & pathname)
	:m_Path(pathname)
{
	ofstream fout("Directory.txt", std::fstream::app);

	string traverse(pathname + "\\*.*");
	WIN32_FIND_DATA file;
	HANDLE DHandle = FindFirstFile(traverse.c_str(),&file);
	if(DHandle != INVALID_HANDLE_VALUE)
	{
		if(FindNextFile(DHandle, &file))
			fout << "Traversing: " << m_Path << '\n';
		
		while (FindNextFile(DHandle, &file))
		{
			string newPath ((m_Path + '\\') + file.cFileName);
			m_Children.Append(new DirectoryTree(newPath));
			fout << '\t' << newPath << '\n';
		}
	}
	fout.close();
	cout << ".";
}
/**********************************************************************	
* Purpose: copy ctor
*
* Entry: passed a directory tree by const ref
*
* Exit: uses op =
*
************************************************************************/
DirectoryTree::DirectoryTree(const DirectoryTree & cpy):m_Path(cpy.m_Path)
{
	*this = cpy;
}
/**********************************************************************	
* Purpose: op =
*
* Entry: passed a directory tree by const ref
*
* Exit: deep copies the tree
*
************************************************************************/
DirectoryTree & DirectoryTree::operator=(const DirectoryTree & rhs)
{
	m_Path = rhs.m_Path;
	while(!m_Children.isEmpty())
		delete m_Children.DeleteLast();

	DoubleLinkedList<DirectoryTree*> temp = rhs.m_Children;
	while(1 != temp.NumItems())
	{
		DirectoryTree* t = new DirectoryTree(*(temp.DeleteLast()));
		m_Children.Append(t);
	}
	return * this;
}
/**********************************************************************	
* Purpose: dtor
*
* Entry:
*
* Exit: deletes all childrens
*
************************************************************************/
DirectoryTree::~DirectoryTree()
{
	while(!m_Children.isEmpty())
		delete m_Children.DeleteLast();
}

#endif