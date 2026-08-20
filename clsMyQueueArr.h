#pragma once

#include <iostream>
#include "clsDaynamicArray.h"

using namespace std;

template <class T> 
class clsMyQueueArr {

protected:

	clsDaynamicArray<T> _MyList;

public:

	void Push(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Pop()
	{
		_MyList.DeleteFirstItem();
	}

	int Size()
	{
		return _MyList.Size();
	}

	int front()
	{
		return _MyList.GetItem(0);
	}

	int back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	void Print()
	{
		_MyList.Print();
	}

	T GetItem(int index)
	{
		return _MyList.GetItem(index);
	}

	void Reverse()
	{
		_MyList.Revrese();
	}

	void UpdateItem(int index, T Value)
	{
		_MyList.SetItem(index, Value);
	}

	void InsertAfter(int index, T Value)
	{
		_MyList.InsertAfter(index, Value);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		Push(Value);
	}

	void Clear()
	{
		_MyList.Clear();
	}








};