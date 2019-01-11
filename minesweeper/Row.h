/************************************************************************
* Class: Row
*
* Purpose: To be able to use the second set of []
*
* Manager functions:	
* 	Row ( )
* 		The default size is zero and the base is zero.  	
*	Row(Array2d<T> & inArray, int row)
*		Creates a Row object and initilized the array2d and row
*	Row (const Array & copy)
*		copy constructor
*	operator = (const Row & copy)
*		overloaded operator =
*	~Row()
*		destructor
*	Getter and setter for row
*
* Methods:		
*	operator [ ] (int index)
*		overloaded to allow for using like the default array.
*************************************************************************/

template<typename T>
class Array2d;

#ifndef ROW_H
#define ROW_H

template<typename T>
class Row
{
public:
	Row();
	~Row();
	Row(const Row &);
	Row(const Array2d<T> & inArray, int row);

	T & operator[](int column)const;
	Row<T> & operator=(const Row<T> & rhs);

	void setRow(int row);
	int getRow() const;

private:
	const Array2d<T> & m_array2d;
	int m_row;
};
/**********************************************************************	
* Purpose: no arg ctor for row
*
* Entry:
*
* Exit: defaults row to 0 and array to null
*
************************************************************************/
	template<typename T>
	Row<T>::Row()
		:m_row(0), m_array2d(nullptr)
	{
	}
/**********************************************************************	
* Purpose: dtor for row
*
* Entry:
*
* Exit: sets row back to default 0
*
************************************************************************/
	template<typename T>
	Row<T>::~Row()
	{
		m_row = 0;
	}
/**********************************************************************	
* Purpose: copy ctor for row
*
* Entry: passed a const row by ref
*
* Exit: copies the data over
*
************************************************************************/
	template<typename T>
	Row<T>::Row(const Row & in)
		:m_array2d(in.m_array2d), m_row(in.m_row)
	{
	}
/**********************************************************************	
* Purpose: 2 arg ctor for row
* 
* Entry: passed a const array2d by ref and an int
*
* Exit: tests to see if row is less than zero, throws exception
*		else assigns the row to the int
*
************************************************************************/
	template<typename T>
	Row<T>::Row(const Array2d<T> & inArray, int row)
		:m_array2d(inArray)
	{
		try{
		if (row < 0)
			throw Exception("cant have less than 0 rows");
		else m_row = row;
		}
		catch(Exception any)
		{
			cout << any;
		}
	}
/**********************************************************************	
* Purpose: overloaded operator []
*
* Entry: passed an int
*
* Exit: returns the appropriate T by calling select
*
************************************************************************/
	template<typename T>
	T & Row<T>::operator[](int column)const
	{
		return m_array2d.Select(m_row, column);
	}
/**********************************************************************	
* Purpose:overloaded operator =
*
* Entry: passed a const row<T> by ref
*
* Exit: checks self assignment and then copies over the data
*
************************************************************************/
	template<typename T>
	Row<T> & Row<T>::operator=(const Row<T> & rhs)
	{
		if (this != &rhs)
		{
			m_array2d = rhs.m_array2d;
			m_row = rhs.m_row;
		}
		return * this;
	}
/**********************************************************************	
* Purpose: setter for row
*
* Entry: passed an int
*
* Exit: returns the row to that int
*
************************************************************************/
	template<typename T>
	void Row<T>::setRow(int row)
	{
		m_array2d.m_array.setLength(row * m_array2d.m_col);
	}
/**********************************************************************	
* Purpose: getter for row
*
* Entry:
*
* Exit: returns the row
*
************************************************************************/
	template<typename T>
	int Row<T>::getRow() const
	{
		return m_row;
	}

#endif