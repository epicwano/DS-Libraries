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
		if (index >= _Size || index < 0)
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

	bool DeleteItemAt(int index)
	{
		if (index >= _Size || index < 0)
			return false;

		_Size--;

		_TempArr = new T[_Size];

		for (int i = 0; i < index; i++)
			_TempArr[i] = OriginalArray[i];


		for (int i = index + 1; i < _Size + 1; i++)
			_TempArr[i - 1] = OriginalArray[i];


		delete[] OriginalArray;
		OriginalArray = _TempArr;
		return true;
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	T Find(T Value)
	{

		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value)
				return i;
		}

		return -1;

	}

	bool DeleteItem(T Value)
	{
		int index = Find(Value);

		if (index == -1)
			return false;

		DeleteItemAt(index);
		return true;
	}

	bool InsertAt(int index,T Value)
	{
		if (index > _Size || index < 0)
			return false;

		_Size++;

		_TempArr = new T[_Size];

		for (int i = 0; i < index; i++)
			_TempArr[i] = OriginalArray[i];

		_TempArr[index] = Value;

		for (int i = index; i < _Size - 1; i++)
			_TempArr[i + 1] = OriginalArray[i];

		delete[] OriginalArray;
		OriginalArray = _TempArr;
		return true;

	}

	void InsertAtBeginning(T Value)
	{
		InsertAt(0,Value);
	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);
	}

	bool InsertBefore(int index, T Value)
	{
		if (index < 1)
			return InsertAt(0, Value);
		else
			return InsertAt(index - 1, Value);
	}

	bool InsertAfter(int index,T Value)
	{
		if (index >= _Size)
			return InsertAt(_Size - 1, Value);
		else
			return InsertAt(index + 1, Value);
	}

};