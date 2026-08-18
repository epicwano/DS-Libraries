#pragma once

#include <iostream>

using namespace std;

template <typename T> 
class clsMyQueue {

private:

	int _Size = 0;
	T *_arr;
	int _front;
	int _back;

public:

	clsMyQueue()
	{
		 _arr = new T[10];
		_front = 0;
		_back = 0;
	}

	T front()
	{
		return _arr[_front];
	}

	T back()
	{
		return _arr[_back - 1];
	}

	int Size()
	{
		return _Size;
	}

	void Print()
	{

		for (int i = 0; i < _Size; i++)
			cout << _arr[_front + i ] << " ";

		cout << "\n";

	}

	void Push(T Value)
	{
		_arr[_back] = Value;
		_back++;
		_Size++;

	}

	void Pop()
	{
		_front++;
		_Size--;
	}

};