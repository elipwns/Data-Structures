/***********************************************************
* Author:		eli kloft
* Lab Number:	CST 211 lab2 sorts
* Filename:		Lab2.cpp
* Date Created:	4/10/13
* Modifications:	4/18/13 
* Overview:
*	This program takes in from the command line how many
*	items to sort. then it makes arrays that big and puts
*	random data into them to be sorted various ways.
*
* Input:
*	needs a number of elements to sort by command line
*
* Output:
*	displays the time each sort took on the screen.
*	prints to file the sorted data as well as the time.
************************************************************/
#include "exception.h"
#include "array.h"
#include "Timer.h"
#include <vector>
using std::vector;
#include <ctime>
using std::rand;
#include <iostream>
#include <fstream>
using std::cout;
using std::ofstream;

void FillUnsortedArray(int * Ra, int items);
template <typename T>
void CopyArray(T & ToCopy, int * RandomNumbers, int items);
template <typename T>
void WriteSortedToFile(T & Ra, int items, ofstream & fout);
template <typename T>
void BubbleSort(T & Ra, int items);
template <typename T>
void BubbleSortFlagged(T & Ra, int items);
int ConvertToInt(char * in);

template<typename T>
void Shell(T & Ra, int items);
template<typename T>
void LinearInsertion(T & Ra, int items);
template<typename T>
void StraightSelection(T & Ra, int items);
template<typename T>
void QuickSort(T & Ra, int first, int last);
template<typename T>
void HeapSort(T & Ra, int items);
template<typename T>
void MergeSort(T & Ra, int items);
template<typename T>
void ShakerSort(T & Ra, int items);
template<typename T>
void m_sort(T & Ra, int left, int right, int * temp);
template<typename T>
void m_merge(T & Ra, int left, int mid, int midplus, int right, int * temp);

int main(int argc, char ** argv)
{
	Timer timer;
	srand(time(NULL));
	ofstream fout("SortedData.txt");
	for(int i(1); i < argc; ++i)
	{
////////CREATE RANDOMS///////////////////////////////////////////////
		int NumberOfItems = ConvertToInt(argv[i]);
		int * RandomNumbers;
		RandomNumbers = new int[NumberOfItems];
		FillUnsortedArray(RandomNumbers, NumberOfItems);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
/////////////////INITIALIZE ARRAYS///////////////////////////////////
		int * NativeInitial = new int [NumberOfItems];
		CopyArray(NativeInitial, RandomNumbers, NumberOfItems);
		vector<int> VectorInitial (NumberOfItems);
		CopyArray(VectorInitial, RandomNumbers, NumberOfItems);
		Array<int> MyArrayInitial(NumberOfItems);
		CopyArray(MyArrayInitial, RandomNumbers, NumberOfItems);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
////////////WRITE RANDOM SET TO FILE/////////////////////////////////
		fout << "Random number set: ";
		for ( int i = 0; i < NumberOfItems; i++)
			fout << RandomNumbers[i] << ", ";
		fout << "\n";
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/////////////BUBBLE SORT//////////////////////////////////////////
		timer.StartTimer();
		BubbleSort(NativeInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Bubble sort Native array time: " << timer.GetTime() << "\n";
		cout << "Bubble sort Native array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(NativeInitial, NumberOfItems, fout);

		timer.StartTimer();
		BubbleSort(MyArrayInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Bubble sort My Array time: " << timer.GetTime() << "\n";
		cout << "Bubble sort My Array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(MyArrayInitial, NumberOfItems, fout);

		timer.StartTimer();
		BubbleSort(VectorInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Bubble sort Vector time: " << timer.GetTime() << "\n";
		cout << "Bubble sort Vector time: " << timer.GetTime() << "\n";
		WriteSortedToFile(VectorInitial, NumberOfItems, fout);
		fout << "\n";
		cout << "\n";
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
////////INITIALIZE ARRAYS////////////////////////////////////////////
		CopyArray(NativeInitial, RandomNumbers, NumberOfItems);
		CopyArray(VectorInitial, RandomNumbers, NumberOfItems);
		CopyArray(MyArrayInitial, RandomNumbers, NumberOfItems);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/////////////BUBBLE SORT FLAGGED///////////////////////////////////////
		timer.StartTimer();
		BubbleSortFlagged(NativeInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Bubble sort flagged Native array time: " << timer.GetTime() 
			 << "\n";
		cout << "Bubble sort flagged Native array time: " << timer.GetTime() 
			 << "\n";
		WriteSortedToFile(NativeInitial, NumberOfItems, fout);

		timer.StartTimer();
		BubbleSortFlagged(MyArrayInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Bubble sort flagged My Array time: " << timer.GetTime()
			 << "\n";
		cout << "Bubble sort flagged My Array time: " << timer.GetTime()
			 << "\n";
		WriteSortedToFile(MyArrayInitial, NumberOfItems, fout);

		timer.StartTimer();
		BubbleSortFlagged(VectorInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Bubble sort flagged Vector time: " << timer.GetTime() << "\n";
		cout << "Bubble sort flagged Vector time: " << timer.GetTime() << "\n";
		WriteSortedToFile(VectorInitial, NumberOfItems, fout);
		fout << "\n";
		cout << "\n";
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
////////INITIALIZE ARRAYS////////////////////////////////////////////
		CopyArray(NativeInitial, RandomNumbers, NumberOfItems);
		CopyArray(VectorInitial, RandomNumbers, NumberOfItems);
		CopyArray(MyArrayInitial, RandomNumbers, NumberOfItems);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/////////////Shell///////////////////////////////////////
		timer.StartTimer();
		Shell(NativeInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Shell Native array time: " << timer.GetTime() << "\n";
		cout << "Shell Native array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(NativeInitial, NumberOfItems, fout);

		timer.StartTimer();
		Shell(MyArrayInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Shell My Array time: " << timer.GetTime() << "\n";
		cout << "Shell My Array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(MyArrayInitial, NumberOfItems, fout);

		timer.StartTimer();
		Shell(VectorInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Shell Vector time: " << timer.GetTime() << "\n";
		cout << "Shell Vector time: " << timer.GetTime() << "\n";
		WriteSortedToFile(VectorInitial, NumberOfItems, fout);
		fout << "\n";
		cout << "\n";
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
////////INITIALIZE ARRAYS////////////////////////////////////////////
		CopyArray(NativeInitial, RandomNumbers, NumberOfItems);
		CopyArray(VectorInitial, RandomNumbers, NumberOfItems);
		CopyArray(MyArrayInitial, RandomNumbers, NumberOfItems);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/////////////LinearInsertion///////////////////////////////////////
		timer.StartTimer();
		LinearInsertion(NativeInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Linear Insertion Native array time: " << timer.GetTime() 
			 << "\n";
		cout << "Linear Insertion Native array time: " << timer.GetTime() 
			 << "\n";
		WriteSortedToFile(NativeInitial, NumberOfItems, fout);

		timer.StartTimer();
		LinearInsertion(MyArrayInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Linear Insertion My Array time: " << timer.GetTime() << "\n";
		cout << "Linear Insertion My Array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(MyArrayInitial, NumberOfItems, fout);

		timer.StartTimer();
		LinearInsertion(VectorInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Linear Insertion Vector time: " << timer.GetTime() << "\n";
		cout << "Linear Insertion Vector time: " << timer.GetTime() << "\n";
		WriteSortedToFile(VectorInitial, NumberOfItems, fout);
		fout << "\n";
		cout << "\n";
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
////////INITIALIZE ARRAYS////////////////////////////////////////////
		CopyArray(NativeInitial, RandomNumbers, NumberOfItems);
		CopyArray(VectorInitial, RandomNumbers, NumberOfItems);
		CopyArray(MyArrayInitial, RandomNumbers, NumberOfItems);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/////////////Straight selection///////////////////////////////////////
		timer.StartTimer();
		StraightSelection(NativeInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Straight selection Native array time: " << timer.GetTime() 
			 << "\n";
		cout << "Straight selection Native array time: " << timer.GetTime() 
			 << "\n";
		WriteSortedToFile(NativeInitial, NumberOfItems, fout);

		timer.StartTimer();
		StraightSelection(MyArrayInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Straight selection My Array time: " << timer.GetTime() << "\n";
		cout << "Straight selection My Array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(MyArrayInitial, NumberOfItems, fout);

		timer.StartTimer();
		StraightSelection(VectorInitial, NumberOfItems);
		timer.StopTimer();
		fout << "Straight selection Vector time: " << timer.GetTime() << "\n";
		cout << "Straight selection Vector time: " << timer.GetTime() << "\n";
		WriteSortedToFile(VectorInitial, NumberOfItems, fout);
		fout << "\n";
		cout << "\n";
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
////////INITIALIZE ARRAYS////////////////////////////////////////////
		CopyArray(NativeInitial, RandomNumbers, NumberOfItems);
		CopyArray(VectorInitial, RandomNumbers, NumberOfItems);
		CopyArray(MyArrayInitial, RandomNumbers, NumberOfItems);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/////////////QuickSort///////////////////////////////////////
		timer.StartTimer();
		QuickSort(NativeInitial, 0, NumberOfItems - 1);
		timer.StopTimer();
		fout << "Quick Sort Native array time: " << timer.GetTime() << "\n";
		cout << "Quick Sort Native array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(NativeInitial, NumberOfItems, fout);

		timer.StartTimer();
		QuickSort(MyArrayInitial, 0, NumberOfItems - 1);
		timer.StopTimer();
		fout << "Quick Sort My Array time: " << timer.GetTime() << "\n";
		cout << "Quick Sort My Array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(MyArrayInitial, NumberOfItems, fout);

		timer.StartTimer();
		QuickSort(VectorInitial, 0, NumberOfItems - 1);
		timer.StopTimer();
		fout << "Quick Sort Vector time: " << timer.GetTime() << "\n";
		cout << "Quick Sort Vector time: " << timer.GetTime() << "\n";
		WriteSortedToFile(VectorInitial, NumberOfItems, fout);
		fout << "\n";
		cout << "\n";
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
////////INITIALIZE ARRAYS////////////////////////////////////////////
		CopyArray(NativeInitial, RandomNumbers, NumberOfItems);
		CopyArray(VectorInitial, RandomNumbers, NumberOfItems);
		CopyArray(MyArrayInitial, RandomNumbers, NumberOfItems);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/////////////HeapSort///////////////////////////////////////
		timer.StartTimer();
		HeapSort(NativeInitial, NumberOfItems);
		timer.StopTimer();
		fout << "HeapSort Native array time: " << timer.GetTime() << "\n";
		cout << "HeapSort Native array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(NativeInitial, NumberOfItems, fout);

		timer.StartTimer();
		HeapSort(MyArrayInitial, NumberOfItems);
		timer.StopTimer();
		fout << "HeapSort My Array time: " << timer.GetTime() << "\n";
		cout << "HeapSort sort My Array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(MyArrayInitial, NumberOfItems, fout);

		timer.StartTimer();
		HeapSort(VectorInitial, NumberOfItems);
		timer.StopTimer();
		fout << "HeapSort Vector time: " << timer.GetTime() << "\n";
		cout << "HeapSort Vector time: " << timer.GetTime() << "\n";
		WriteSortedToFile(VectorInitial, NumberOfItems, fout);
		fout << "\n";
		cout << "\n";
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
////////INITIALIZE ARRAYS////////////////////////////////////////////		
		CopyArray(NativeInitial, RandomNumbers, NumberOfItems);
		CopyArray(VectorInitial, RandomNumbers, NumberOfItems);
		CopyArray(MyArrayInitial, RandomNumbers, NumberOfItems);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/////////////MergeSort///////////////////////////////////////
		timer.StartTimer();
		MergeSort(NativeInitial, NumberOfItems);
		timer.StopTimer();
		fout << "MergeSort Native array time: " << timer.GetTime() << "\n";
		cout << "MergeSort Native array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(NativeInitial, NumberOfItems, fout);

		timer.StartTimer();
		MergeSort(MyArrayInitial, NumberOfItems);
		timer.StopTimer();
		fout << "MergeSort My Array time: " << timer.GetTime() << "\n";
		cout << "MergeSort My Array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(MyArrayInitial, NumberOfItems, fout);

		timer.StartTimer();
		MergeSort(VectorInitial, NumberOfItems);
		timer.StopTimer();
		fout << "MergeSort Vector time: " << timer.GetTime() << "\n";
		cout << "MergeSort Vector time: " << timer.GetTime() << "\n";
		WriteSortedToFile(VectorInitial, NumberOfItems, fout);
		fout << "\n";
		cout << "\n";
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
////////INITIALIZE ARRAYS////////////////////////////////////////////		
		CopyArray(NativeInitial, RandomNumbers, NumberOfItems);
		CopyArray(VectorInitial, RandomNumbers, NumberOfItems);
		CopyArray(MyArrayInitial, RandomNumbers, NumberOfItems);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
/////////////ShakerSort///////////////////////////////////////
		timer.StartTimer();
		ShakerSort(NativeInitial, NumberOfItems);
		timer.StopTimer();
		fout << "ShakerSort Native array time: " << timer.GetTime() << "\n";
		cout << "ShakerSort Native array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(NativeInitial, NumberOfItems, fout);

		timer.StartTimer();
		ShakerSort(MyArrayInitial, NumberOfItems);
		timer.StopTimer();
		fout << "ShakerSort My Array time: " << timer.GetTime() << "\n";
		cout << "ShakerSort My Array time: " << timer.GetTime() << "\n";
		WriteSortedToFile(MyArrayInitial, NumberOfItems, fout);

		timer.StartTimer();
		ShakerSort(VectorInitial, NumberOfItems);
		timer.StopTimer();
		fout << "ShakerSort Vector time: " << timer.GetTime() << "\n";
		cout << "ShakerSort Vector time: " << timer.GetTime() << "\n";
		WriteSortedToFile(VectorInitial, NumberOfItems, fout);
		fout << "\n";
		cout << "\n";
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/	
	}
	fout.close();
	system("Pause");
}
/**********************************************************************	
* Purpose: Fills array with random data
*
* Entry: passed a pointer to an array and its size
*
* Exit: fills array with random data
************************************************************************/
void FillUnsortedArray(int * Ra, int items)
{
	for (int i = 0; i < items; ++i)
	{
		Ra[i] = rand();
	}
}
/**********************************************************************	
* Purpose: copies random data to other arrays
*
* Entry: passed a T by ref, the random numbers by pointer, and an int
*
* Exit: copies the random data to the array
************************************************************************/
template <typename T>
void CopyArray(T & ToCopy, int * RandomNumbers, int items)
{
	for(int i = 0; i < items; ++i)
	{
		ToCopy[i] = RandomNumbers[i];
	}
}
/**********************************************************************	
* Purpose: writes the data to file
*
* Entry: passed a T by ref and the number of items and fout
*
* Exit: deletes the message 
************************************************************************/
template <typename T>
void WriteSortedToFile(T & Ra, int items, ofstream & fout)
{
	for (int i = 0; i < items; i++)
	{
		fout << Ra[i] << ((i!=i-1)?", ":"");
	}
	fout << "\n";
}
/**********************************************************************	
* Purpose: the Bubble Sort
*
* Entry: passed a T by ref and the number of items
*
* Exit: Makes multiple passes moving the highest item to the last spot
************************************************************************/
template <typename T>
void BubbleSort(T & Ra, int items)
{
	while (items > 0)
	{
		for(int i = 1; i < items; ++i)
		{
			if (Ra[i] < Ra[i - 1])
			{
				int temp = Ra[i-1];
				Ra[i - 1] = Ra[i];
				Ra[i] = temp;
			}
		}
		--items;
	}
}
/**********************************************************************	
* Purpose: the Bubble Sort Flagged
*
* Entry: passed a T by ref and the number of items
*
* Exit: a smarter bubble sort that uses a sorted flag
************************************************************************/
template <typename T>
void BubbleSortFlagged(T & Ra, int items)
{
	bool sorted = false;
	int runs = 0;
	while(!sorted)
	{
		sorted = true;
		for ( int i = 1; i < items - runs; ++i)
			if (Ra[i] < Ra[i - 1])
			{
				int temp = Ra[i-1];
				Ra[i - 1] = Ra[i];
				Ra[i] = temp;
				sorted = false;
			}
		++runs;
	}
}
/**********************************************************************	
* Purpose: converts character number to int
*
* Entry: passed a char *
*
* Exit: returns the int version of the char * number
************************************************************************/
int ConvertToInt(char * in)
{
	int n = 0;
	char * temp = in;
	for (int i = 0; * temp >= 0x30 && * temp <= 0x39; ++temp)
	{
		n *= 10;
		n += * temp - 0x30;
	}
	return n;
}
/**********************************************************************	
* Purpose: the Shell Sort
*
* Entry: passed a T by ref and the number of items
*
* Exit: does linear insertion on items first far apart and gets closer
************************************************************************/
template<typename T>
void Shell(T & Ra, int items)
{
	int initialsize = 1;
	while(initialsize < items)
		((initialsize *= 3) += 1);

	for(int k = initialsize; ((k -= 1) /= 3);)
	{
		for(int start = k; start < items; start +=k) 
		{
			if(Ra[start] < Ra[start - k])
			{
				int temp = Ra[start];
				int j;
				for(j = start; j > 0 && temp < Ra[j-k]; j -= k)
				{
					Ra[j] = Ra[j - k];
				}
				Ra[j] = temp;
			}
		}
	}
}
/**********************************************************************	
* Purpose: Linear Insertion
*
* Entry: passed a T by ref and the number of items
*
* Exit: finds lowest, moves everything over and inserts it
************************************************************************/
template<typename T>
void LinearInsertion(T & Ra, int items)
{
	int sorted = 1;
	
	while(sorted < items)
	{
		for ( int i = 0; i < sorted; ++i)
		{
			if(Ra[i] > Ra[sorted])
			{
				int temp = Ra[sorted];
				for (int j = sorted; j > i; --j)
					Ra[j] = Ra[j-1];
				Ra[i] = temp;
			}
		}
		++sorted;
	}
}
/**********************************************************************	
* Purpose: Straight Selection
*
* Entry: passed a T by ref and the number of items
*
* Exit: selects an item and puts it into the correct spot
************************************************************************/
template<typename T>
void StraightSelection(T & Ra, int items)
{
	int tempi;
	bool flag = false;
	for ( int j = 0; j < items; ++j)
	{
		int temp = Ra[j];
		for ( int i = j; i < items; ++i)
		{
			if (Ra[i] < temp)
			{
				temp = Ra[i];
				tempi = i;
				flag = true;
			}
		}
		if(flag)
		{
			Ra[tempi] = Ra[j];
			Ra[j] = temp;
		}
		flag = false;
	}
}
/**********************************************************************	
* Purpose: the Quick Sort
*
* Entry: passed a T by ref and the number of items
*
* Exit: sorts by moving data using multiple pivots
************************************************************************/
template<typename T>
void QuickSort(T & Ra, int  first, int last)
{
	int pivot = Ra[first];
	int lower = first + 1;
	int upper = last;
	
	do
	{
		for(upper; upper > lower && Ra[upper] >= pivot; --upper);
		for(lower; lower < upper && Ra[lower] <= pivot; ++lower);

		if(lower < upper)
		{
			Ra[lower] ^= Ra[upper];
			Ra[upper] ^= Ra[lower];
			Ra[lower] ^= Ra[upper];
		}
			
	}while(lower < upper);

		if (Ra[upper] < Ra[first])
		{
			Ra[first] ^= Ra[upper];
			Ra[upper] ^= Ra[first];
			Ra[first] ^= Ra[upper];
		}

		if(lower - first >= 2)
			QuickSort(Ra, first, lower - 1);
		if(last - lower >= 1)
			QuickSort(Ra, lower, last);
}
/**********************************************************************	
* Purpose: the Heap Sort
*
* Entry: passed a T by ref and the number of items
*
* Exit: sorts the data by heaping everything, taking off the top,
*		and resorting
************************************************************************/
template<typename T>
void HeapSort(T & Ra, int items)
{
	int tempfirst;
	int last = items - 1;
	int first = ((last / 2) - 1);
	int largest = ((first * 2) + 1);

	while(first >= 0)
	{
		tempfirst = first;
		while(largest <= last)
		{
			if(largest + 1 <= last)
				if(Ra[largest] < Ra[largest + 1])
					largest++;
			if(Ra[largest] > Ra[first])
			{
				Ra[largest] ^= Ra[first];
				Ra[first] ^= Ra[largest];
				Ra[largest] ^= Ra[first];
			}
			first = largest;
			largest = ((first * 2) + 1);
		}
		first = tempfirst - 1;
		largest = ((first * 2) + 1);
	}
	
	Ra[0] ^= Ra[last];
	Ra[last] ^= Ra[0];
	Ra[0] ^= Ra[last];
	--last;

	while(last != 0)
	{
		first = 0;
		largest = ((first * 2) + 1);
		while (largest <= last)
		{
			if(largest + 1 <= last)
				if(Ra[largest] < Ra[largest + 1])
					largest++;
			if(Ra[largest] > Ra[first])
			{
				Ra[largest] ^= Ra[first];
				Ra[first] ^= Ra[largest];
				Ra[largest] ^= Ra[first];
			}
			first = largest;
			largest = ((first * 2) + 1);
		}
		
		Ra[0] ^= Ra[last];
		Ra[last] ^= Ra[0];
		Ra[0] ^= Ra[last];
		last--;
	}
}
/**********************************************************************	
* Purpose: The Merge Sort
*
* Entry: passed the T array by ref and the number of items
*
* Exit: makes a temp array and then passes the parameters to sort
************************************************************************/
template<typename T>
void MergeSort(T & Ra, int items)
{
	int * temp(new int[(items / 2) + 1]);
	m_sort(Ra, 0, items - 1, temp);
	delete [] temp;
}
/**********************************************************************	
* Purpose: Recursive part of the merge
*
* Entry: passsed a T by ref, the left bounds, the right bounds, 
*		 and the temp array
*
* Exit: calls the actuall merge part of the merge sort
************************************************************************/
template<typename T>
void m_sort(T & Ra, int left, int right, int * temp)
{
	int middle;
	
	middle = ((left + right) / 2);
	if(middle + 1 < right)
		m_sort(Ra, middle + 1, right, temp);
	if (left < middle )
		m_sort(Ra, left , middle, temp);

	m_merge(Ra, left, middle, middle + 1, right, temp);
}
/**********************************************************************	
* Purpose: the Merge sort
*
* Entry: passed a T by ref and the bounds of the 2 parts of the array
*
* Exit: sorts the data
************************************************************************/
template<typename T>
void m_merge(T & Ra, int left, int mid, int midplus, int right, int * temp)
{
	if(left <= mid && right >= midplus)
	{
		for(int i = 0, j = left; j <= mid; ++i, ++j)
			temp[i] = Ra[j];
		int index (left);
		int tempi (0);
		while(tempi <= (mid - left) && midplus <= right)
			Ra[index++] = ((temp[tempi] < Ra[midplus]) ? temp[tempi++]:Ra[midplus++]);
		while(tempi <= (mid - left))
			Ra[index++] = temp[tempi++];
		while(midplus <= right)
			Ra[index++] = Ra[midplus++];
	}
}
/**********************************************************************	
* Purpose: Shaker Sort
*
* Entry: passed a T by ref and the number of items
*
* Exit: like the bubble sort but goes up and down
************************************************************************/
template<typename T>
void ShakerSort(T & Ra, int items)
{
	int sorted = 1;
	while (items > 0)
	{
		for(int i = sorted; i < items; i++)
		{
			if (Ra[i] < Ra[i - 1])
			{
				int temp = Ra[i-1];
				Ra[i - 1] = Ra[i];
				Ra[i] = temp;
			}
		}
		items--;
		for(int j = items; j >= sorted; j--)
		{
			if(Ra[j] < Ra[j-1])
			{
				Ra[j] ^= Ra[j-1];
				Ra[j-1] ^= Ra[j];
				Ra[j] ^= Ra[j-1];
			}
		}
		sorted++;
	}
}