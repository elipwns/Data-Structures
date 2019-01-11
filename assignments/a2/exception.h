/************************************************************************
* Class: Exception
*
* Purpose: this class manages the Exceptions
*
* Manager functions:	
*	Exception(char *) - ctor, passed a char* that is put into the m_msg
*	overloaded operator =
*	getter and setter for m_msg
*	Dtor deletes m_msg
* Methods:		
*		
*************************************************************************/

#include <iostream>
using std::ostream;

#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception
{
public:
	friend ostream & operator<<(ostream & stream, const Exception & except);

	Exception();
	~Exception();
	Exception(char * msg);
	Exception(const Exception &);

	Exception & operator=(const Exception & rhs);

	char * GetMessage() const;
	void SetMessage(char * msg);

private:
	char * m_msg;
};


#endif