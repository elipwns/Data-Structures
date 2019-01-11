#include "exception.h"
/**********************************************************************	
* Purpose: no arg ctor for exception
*
* Entry: 
*
* Exit: sets mesage to null
*
************************************************************************/

Exception::Exception()
	:m_msg (nullptr)
{
}
/**********************************************************************	
* Purpose: exception dtor
*
* Entry: 
*
* Exit: deletes the message 
************************************************************************/

Exception::~Exception()
{
	delete [] m_msg;
	m_msg = nullptr;
}
/**********************************************************************	
* Purpose: exception 1 arg ctor
*
* Entry: passed a char *
*
* Exit: copies the msg from the char *
*
************************************************************************/

Exception::Exception(char * msg)
{
	m_msg = new char[strlen(msg) + 1];
	strcpy_s(m_msg, strlen(msg) + 1, msg);
}
/**********************************************************************	
* Purpose: copy ctor for exception
*
* Entry: passed a const exception by ref
*
* Exit: copies over the message
*
************************************************************************/

Exception::Exception(const Exception & rhs)
{
	m_msg = new char[strlen(rhs.GetMessage()) + 1];
	strcpy_s(m_msg, strlen(rhs.GetMessage()) + 1, rhs.GetMessage());
}
/**********************************************************************	
* Purpose: overloaded operator =
*
* Entry: passed a const exception by ref
*
* Exit: sets the message to the rhs message
*
************************************************************************/

Exception & Exception::operator=(const Exception & rhs)
{
	this->SetMessage(rhs.GetMessage());
	return *this;
}
/**********************************************************************	
* Purpose: getter for message
*
* Entry: 
*
* Exit: returns the message
*
************************************************************************/

char * Exception::GetMessage() const
{
	return m_msg;
}
/**********************************************************************	
* Purpose: setter for message
*
* Entry: passed a char *
*
* Exit: copies the char * to the message
*
************************************************************************/

void Exception::SetMessage(char * msg)
{
	delete [] m_msg;
	m_msg = new char [strlen(msg) + 1];
	strcpy_s(m_msg, strlen(msg) + 1, msg);
}
/**********************************************************************	
* Purpose: overloaded operator <<
*
* Entry: passed a ostream by ref and a const exception by ref
*
* Exit: loads stream with the message and returns it
*
************************************************************************/

ostream & operator<<(ostream & stream, const Exception & except)
{
	return stream << except.GetMessage();
}
