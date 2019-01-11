/************************************************************************
* Class: Abstract Iterator
*
* Purpose: sets up the interface functions
*
* Manager functions:	
*
* Methods:		
*	void MoveNext() - pure virtual, moves to next item
*	void Reset() - pure virtual, resets the list
*	bool IsDone() - pure virtual, checks if at end of list
*	T GetCurrent()const - pure virtual
*	T & GetCurrent() - pure virtual
*
*	 ~AbstractIterator(){} - virtual dtor
*************************************************************************/

#ifndef ABSTRACTITERATOR_H
#define ABSTRACTITERATOR_H

template<typename T>
class AbstractIterator
{
public:
	virtual	void MoveNext() = 0;
	virtual void Reset() = 0;
	virtual bool IsDone() = 0;
	virtual T GetCurrent()const = 0;
	virtual T & GetCurrent() = 0;

	virtual ~AbstractIterator(){}
private:
};


#endif