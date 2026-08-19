#pragma once

#include <iostream>



using namespace std;

template <class T> 
class clsDaynamicArray
{

protected:

	int _Size = 0;
	T* _TempArr;


public:

	T* OriginalArray;

	clsDaynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;

		OriginalArray = new T[Size];
	}

	~clsDaynamicArray()
	{
		delete[] OriginalArray;
	}

	bool IsEmpty()
	{
		return _Size == 0 ? true : false;
	}

	int Size()
	{
		return _Size;
	}

	bool SetItem(int index,T Value)
	{
		if (index >= _Size || index < 0)
			return false;

		*(OriginalArray + index) = Value;
		return true;
	}

	void Print()
	{

		for (int i = 0; i < _Size; i++)
			cout << OriginalArray[i] << " ";

		cout << "\n";

	}

	void Resize(int NewSize)
	{

		if (NewSize < 0)
			NewSize = 0;

		_TempArr = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; i++)
			_TempArr[i] = OriginalArray[i];

		// this line because it if the if sastatment dosn`t apply
		_Size = NewSize;

		delete[] OriginalArray;
		OriginalArray = _TempArr;
	}

	T GetItem(int index)
	{
		if (index > _Size || index < 0)
			return -1;

		return OriginalArray[index];
	}

	void Revrese()
	{
		_TempArr = new T[_Size];

		int Counter = 0;

		for (int i = _Size - 1; i >= 0; i--) 
		{
			_TempArr[Counter] = OriginalArray[i];
			Counter++;
		}

		delete[] OriginalArray;
		OriginalArray = _TempArr;
	}
	
	void Clear()
	{
		_Size = 0;
		_TempArr = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArr;
	}

};