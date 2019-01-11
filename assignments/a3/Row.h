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

	int getRow() const;

private:
	const Array2d<T> & m_array2d;
	int m_row;
};

	template<typename T>
	Row<T>::Row()
		:m_row(0), m_array2d(nullptr)
	{
	}

	template<typename T>
	Row<T>::~Row()
	{
		m_row = 0;
	}

	template<typename T>
	Row<T>::Row(const Row & in)
		:m_array2d(in.m_array2d), m_row(in.m_row)
	{
	}

	template<typename T>
	Row<T>::Row(const Array2d<T> & inArray, int row)
		:m_array2d(inArray), m_row(row)
	{
		if (row < 0)
			throw Exception("cant have less than 0 rows");
	}

	template<typename T>
	T & Row<T>::operator[](int column)const
	{
		return m_array2d.Select(m_row, column);
	}

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

	template<typename T>
	int Row<T>::getRow() const
	{
		return m_row;
	}

#endif