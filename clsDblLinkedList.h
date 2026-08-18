#pragma once

#include <iostream>

using namespace std;

template <typename T> 
class clsDblLinkedList
{

private:

	int _Size = 0;

public:


	class Node {

	public:

		Node* next;
		T Value;
		Node* prev;
	};

	Node* Head = NULL;
	
	// Mehods

	Node* Find(T Value)
	{
		Node* Current = Head;

		while (Current != NULL)
		{
			if (Current->Value == Value)
				return Current;

			Current = Current->next;

		}

		return NULL;

	}

	void PrintList()
	{
		Node* Current = Head;

		while (Current != NULL) {
			cout << Current->Value << " ";
			Current = Current->next;
		}

		cout << "\n";
		delete Current;

	}

	void InsertAtBeginning(T Value)
	{

		Node* NewNode = new Node();
		NewNode->Value = Value;
		NewNode->next = Head;
		NewNode->prev = NULL;

		if (Head != NULL)
			Head->prev = NewNode;

		Head = NewNode;
		_Size++;
	}

	void InsertAfter(Node* Current, T Value)
	{
		if (Current == NULL)
			return;


		Node* NewNode = new Node();
		NewNode->Value = Value;
		NewNode->prev = Current;
		NewNode->next = Current->next;

		if (Current->next != NULL)
			Current->next->prev = NewNode;

		Current->next = NewNode;
		_Size++;
	}

	void InsertAtEnd(T Value)
	{

		Node* NewNode = new Node();
		NewNode->Value = Value;
		NewNode->next = NULL;

		if (Head == NULL)
		{

			NewNode->prev = NULL;
			Head = NewNode;
		}
		else {

			Node* Current = Head;

			while (Current->next != NULL)
				Current = Current->next;

			Current->next = NewNode;
			NewNode->prev = Current;

		}

		_Size++;

	}

	void DeleteNode(Node*& NodeToDelete)
	{

		if (Head == NULL || NodeToDelete == NULL)
			return;


		if (Head == NodeToDelete)
			Head = NodeToDelete->next;

		if (NodeToDelete->next != NULL)
			NodeToDelete->next->prev = NodeToDelete->prev;

		if (NodeToDelete->prev != NULL)
			NodeToDelete->prev->next = NodeToDelete->next;


		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{

		if (Head == NULL)
			return;


		Node* FirstNode = Head;

		Head = FirstNode->next;

		if (Head != NULL)
			Head->prev = NULL;

		delete FirstNode;
		_Size--;
	}

	void DeleteLastNode()
	{

		if (Head == NULL)
			return;


		if (Head->next == NULL) {

			delete Head;
			Head = NULL;
			_Size--;
			return;
		}

		Node* Current = Head;

		// this loop will Get the node before the last node
		while (Current->next->next != NULL)
			Current = Current->next;

		Node* LastNode = Current->next;

		Current->next = NULL;

		delete LastNode;
		_Size--;
	}

	short Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	void Clear()
	{
		while (_Size > 0)
			DeleteFirstNode();
	}

	void Reverse()
	{

		Node* Current = Head;
		Node* Temp = nullptr;

		while (Current != nullptr)
		{
			Temp = Current->prev;
			Current->prev = Current->next;
			Current->next = Temp;
			Current = Current->prev;
		}

		if (Temp != nullptr)
			Head = Temp->prev;
	}

	Node* GetNode(int Index)
	{
		int CurrentIndex = 0;

		if (Index > _Size - 1 || Index < 0)
			return nullptr;

		Node* Current = Head;

		while (Current != nullptr && (Current->next != nullptr)) {

			if (CurrentIndex == Index)
				break;

			Current = Current->next;
			CurrentIndex++;
		}

		return Current;

	}

	T GetItem(int Index)
	{
		
		Node* ItemNode = GetNode(Index);

		if (ItemNode == NULL)
			return T{};
		else
			return ItemNode->Value;

	}

};