/************************************************************************
* Class: Array2d
*
* Purpose: This class creates a dynamic one-dimensional array that can be 
* started at any base. 
*
* Manager functions:	
* 	Array2d ( )
* 		The default size is zero 	
*	Array2d (int rows, int cols)
*		Creates an appropriate sized array
*	Array2d (const Array & copy)
*		copy constructor
*	operator = (const Array & copy)
*		overloaded operator =
*	~Array2d()
*		destructor
*	T & Select(int row, int column)
*		goes to the correct element and returns it
*	getters and setters for row and column
*
* Methods:		
*	operator [ ] (int index)
*		overloaded to allow for using like the default array.
*************************************************************************/

#include "array.h"
#include "Row.h"

#ifndef ARRAY2D_H
#define ARRAY2D_H

template <typename T>
class Array2d
{
public:
	Array2d();
	~Array2d();
	Array2d(const Array2d<T> & in);
	Array2d(int row, int col = 0);

	Array2d<T> & operator=(const Array2d<T> & rhs);
	Row<T> operator[](int index)const;

	int getRow() const;
	void setRow(int rows);
	int getColumn() const;
	void setColumn(int columns);
	T & Select(int row, int column)const;

private:
	Array<T> m_array;
	int m_row;
	int m_col;
};

	template<typename T>
	Array2d<T>::Array2d()
		:m_array(nullptr), m_row(0), m_col(0)
	{
	}

	template<typename T>
	Array2d<T>::~Array2d()
	{
		m_row = 0;
		m_col = 0;
	}

	template<typename T>
	Array2d<T>::Array2d(const Array2d<T> & in)
		:m_col(in.m_col), m_row(in.m_row)
	{
		m_array = in.m_array;
		m_row = in.getRow();
		m_col = in.getColumn();
	}

	template<typename T>
	Array2d<T>::Array2d(int row, int col = 0)
		:m_row(row), m_col(col)
	{
		if (row < 0 || col < 0)
			throw Exception("can't supply negative number");
		m_array = Array<T>(row * col);
	}

	template<typename T>
	Array2d<T> & Array2d<T>::operator=(const Array2d<T> & rhs)
	{
		m_array = rhs.m_array;
		m_row = rhs.m_row;
		m_col = rhs.m_col;
	}

	template<typename T>
	Row<T> Array2d<T>::operator[](int index) const
	{
		if (index > m_row)
			throw Exception("invalid index");
		return Row<T>(* this, index); 
	}


	template<typename T>
	int Array2d<T>::getRow() const
	{
		return m_row;
	}

	template<typename T>
	void Array2d<T>::setRow(int rows)
	{
		if (rows < 0)
			throw Exception("cant have less than 0 rows");
		m_array.SetLength(rows * m_col);
		m_row = rows;
	}

	template<typename T>
	int Array2d<T>::getColumn() const
	{
		return m_col;
	}

	template<typename T>
	void Array2d<T>::setColumn(int columns)
	{
		if (columns < 0)
			throw Exception("cant have less than 0 cols");
		int tempindex = 0;

		Array<T> temp(m_row * columns);
		if(columns > m_col)
		{
			for (int i = 0; i < m_row; i++)
			{
				for(int j = 0; j < m_col; j++)
				{
					temp[tempindex] = m_array[(m_col * i) + j];
					tempindex++;
				}
				tempindex += columns - m_col;
			}
		}
		else
		{
			for(int i = 0; i < m_row; i++)
			{
				for(int j = 0; j < columns; j++)
				{
					temp[tempindex] = m_array[(m_col * i) + j];
					tempindex++;
				}
			}
		}

		m_array = temp;
		m_col = columns;
	}

	template<typename T>
	T & Array2d<T>::Select(int row, int column)const
	{
		if (row > m_row || column > m_col)
			throw Exception("out of bounds");
		return m_array[(row * m_col) + column];
	}


#endif
