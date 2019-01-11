#include "hashnode.h"
#include "hashtable.h"
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

struct Book
{
	string m_title;
	string m_author;
	int m_pages;
};

int AsciiHash(string key);

int main()
{
	HashTable<string, Book> table(10);

	table.setHash(AsciiHash);

	Book temp = {"C++: An Active Learning Approach", "Randal Albert", 635};
	table.Insert("0763757233", temp);

	Book temp1 = {"Rodeo for Dummies", "Calvin Caldwell", 1};
	table.Insert("7063757233", temp1);

	Book temp3 = {"And That n There", "Ralph Carestia", 1};
	table.Insert("7063757234", temp3);

	cout << table["0763757233"].m_title << endl;
	cout << table["7063757233"].m_title << endl;
	cout << table["7063757234"].m_title << endl;

	return 0;
}


int AsciiHash(string key)
{
	int hash = 0;
	for(unsigned int i = 0; i < key.size(); i++)
	{
		hash += key[i];
	}
	hash %= key.size();
	return hash;
}