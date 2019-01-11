#include "Timer.h"
/**********************************************************************	
* Purpose: timer no arg ctor
*
* Entry: 
*
* Exit: sets the time so its not 0
************************************************************************/
Timer::Timer()
{
	GetSystemTime(&m_start);
	GetSystemTime(&m_end);
}
/**********************************************************************	
* Purpose:timer dtor
*
* Entry: 
*
* Exit: 
************************************************************************/
Timer::~Timer()
{
}
/**********************************************************************	
* Purpose: overloaded op =
*
* Entry: passed a timer by ref
*
* Exit: checks for self assignment and then copies over the data
************************************************************************/
Timer & Timer::operator =(const Timer & rhs)
{
	if (this != &rhs)
	{
		m_start = rhs.m_start;
		m_end = rhs.m_end;
	}
	return * this;
}
/**********************************************************************	
* Purpose: time copy ctor
*
* Entry: passed a timer by ref
*
* Exit: copies the data
************************************************************************/
Timer::Timer(const Timer & copy)
{
	m_start = copy.m_start;
	m_end = copy.m_end;
}
/**********************************************************************	
* Purpose: set the start time
*
* Entry: 
*
* Exit: 
************************************************************************/
void Timer::StartTimer()
{
	GetSystemTime(&m_start);
}
/**********************************************************************	
* Purpose: set the end time
*
* Entry: 
*
* Exit: finds the difference between the end and start time and leaves
*		it in end time for ease of use
************************************************************************/
void Timer::StopTimer()
{
	GetSystemTime(&m_end);
	if(m_end.wMilliseconds < m_start.wMilliseconds)
	{
		--m_end.wSecond;
		m_end.wMilliseconds += 1000;
	}
	m_end.wMilliseconds -= m_start.wMilliseconds;
	
	if(m_end.wSecond < m_start.wSecond)
	{
		--m_end.wMinute;
		m_end.wSecond += 60;
	}
	m_end.wSecond -= m_start.wSecond;
	
	if(m_end.wMinute < m_start.wMinute)
	{
		--m_end.wHour;
		m_end.wMinute += 60;
	}
	m_end.wMinute -= m_start.wMinute;
	
	m_end.wHour -= m_start.wHour;
}
/**********************************************************************	
* Purpose: returns the end time
*
* Entry: 
*
* Exit: 
************************************************************************/
SYSTEMTIME & Timer::GetTime()
{
	return m_end;
}
/**********************************************************************	
* Purpose: overloaded operator <<
*
* Entry: passed an ostream and systemtime by ref
*
* Exit: displays the time in easy to read format
************************************************************************/
ostream & operator <<(ostream & stream,const SYSTEMTIME & timer)
{
	return stream << timer.wHour << ":" << timer.wMinute << ":"
		<< timer.wSecond << ":" << timer.wMilliseconds;
}