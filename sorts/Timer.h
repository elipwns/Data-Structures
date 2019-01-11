/************************************************************************
* Class: Timer
*
* Purpose: easy way to time how long a function takes to complete
*
* Manager functions:	
*	Timer() - ctor
*	Timer(const Timer &) - copy ctor
*	overloaded operator =
* Methods:		
*	Stop Timer - stops timer and subtracts start time from stop time
*	Start timer - sets m_start to the current time
*	Get time - returns time structure
*************************************************************************/
#include <iostream>
using std::ostream;
#include <Windows.h>

#ifndef TIMER_H
#define TIMER_H

class Timer
{
	friend ostream & operator << (ostream & stream, const SYSTEMTIME & time);
public:
	Timer();
	~Timer();
	Timer & operator =(const Timer &);
	Timer(const Timer &);

	void StartTimer();
	void StopTimer();
	SYSTEMTIME & GetTime();
private:
	SYSTEMTIME m_start;
	SYSTEMTIME m_end;
};


#endif