#include "exception.h"

Exception::Exception()
	:m_msg (nullptr)
{
}

Exception::~Exception()
{
	delete [] m_msg;
	m_msg = nullptr;
}

Exception::Exception(char * msg)
{
	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}

Exception::Exception(const Exception & rhs)
{
	m_msg = new char[strlen(rhs.GetMessage()) + 1];
	strcpy(m_msg, rhs.GetMessage());
}

Exception & Exception::operator=(const Exception & rhs)
{
	this->SetMessage(rhs.GetMessage());
	return *this;
}

char * Exception::GetMessage() const
{
	return m_msg;
}

void Exception::SetMessage(char * msg)
{
	delete [] m_msg;
	m_msg = new char [strlen(msg) + 1];
	strcpy(m_msg, msg);
}

ostream & operator<<(ostream & stream, const Exception & except)
{
	return stream << except.GetMessage();
}
