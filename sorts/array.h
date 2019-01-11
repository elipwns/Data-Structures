/************************************************************************
* Class: Array
*
* Purpose: This class creates a dynamic one-dimensional array that can be 
* started at any base. 
*
* Manager functions:	
* 	Array ( )
* 		The default size is zero and the base is zero.  	
*	Array (int length, int start_index = 0)
*		Creates an appropriate sized array with the starting index 
*              either zero or the supplied starting value.
*	Array (const Array & copy)
*		copy constructor
*	operator = (const Array & copy)
*		overloaded operator =
*	~Array()
*		destructor
*	Get and set for length and start index
*
* Methods:		
*	operator [ ] (int index)
*		overloaded to allow for using like the default array.
*************************************************************************/

#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array
{
public:
	Array();
	~Array();
	Array(int length, int start_index = 0);
	Array(const Array & rhs);

	Array & operator=(const Array & rhs);
	T & operator[](int index);

	int GetLength() const;
	void SetLength(int length);
	int GetStartIndex() const;
	void SetStartIndex(int index);

private:
	T * m_array;
	int m_length;
	int m_start_index;
};


	template <typename T>
	Array<T>::Array()
		:m_array(nullptr), m_length(0), m_start_index(0)
	{
	}

	template <typename T>
	Array<T>::~Array()
	{
		delete [] m_array;
		m_array = nullptr;
		m_length = 0;
		m_start_index = 0;
	}

	template <typename T>
	Array<T>::Array(int length, int start_index = 0)
		:m_length(length), m_start_index(start_index)
	{
		if (length < 0)
			throw true;
		else
			m_array = new T[length]; 
	}

	template <typename T>
	Array<T>::Array(const Array<T> & rhs)
		:m_length(rhs.m_length), m_start_index(rhs.m_start_index)
	{
		m_array = new T [rhs.m_length];
		for (int i = 0; i < rhs.GetLength(); i++)
		{
			m_array[i] = rhs.m_array[i];
		}
	}
		
	template <typename T>
	Array<T> & Array<T>::operator=(const Array<T> & rhs)
	{
		if (this != &rhs)
		{
			delete [] m_array;
			m_array = new T[rhs.m_length];
			m_length = rhs.m_length;
			m_start_index = rhs.m_start_index;
			for (int i = 0; i < rhs.GetLength(); i++)
				m_array[i] = rhs.m_array[i];
		}
		return * this;
	}

	template <typename T>
	T & Array<T>::operator[](int index)
	{
		index -= m_start_index;
		if (index >= 0 && index < m_length)
			return m_array[index];
		else
			throw true;
	}

	template <typename T>
	int Array<T>::GetLength() const
	{
		return m_length;
	}

	template <typename T>
	void Array<T>::SetLength(int length)
	{
		if (m_length != length)
		{
			Array<T> temp(*this);
			delete [] this->m_array;
			m_array = new T[length];

			if (length > m_length)
				for (int i = 0; i < m_length; i++)
					m_array[i] = temp[i];
			else
				for (int i = 0; i < length; i++)
					m_array[i] = temp[i];

			m_length = length;
		}	
	}

	template <typename T>
	int Array<T>::GetStartIndex() const
	{
		return m_start_index;
	}

	template <typename T>
	void Array<T>::SetStartIndex(int index)
	{
		m_start_index = index;
	}

#endif
