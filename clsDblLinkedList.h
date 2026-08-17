#pragma once

#include <iostream>

using namespace std;

template <typename T> 
class clsDblLinkedList
{

public:

	struct Node {

		Node* next;
		T Value;
		Node* prev;
	};

	Node* Head = NULL;
	
	// Mehods

	Node* Find(T Value)
	{
		Node* TempHead = Head;

		while (TempHead != NULL)
		{
			if (TempHead->Value == Value)
				return TempHead;

			TempHead = TempHead->next;

		}

		return NULL;

	}

	void PrintList()
	{
		Node* TempHead = Head;

		cout << "\n";

		while (TempHead != NULL) {
			cout << TempHead->Value << " ";
			TempHead = TempHead->next;
		}

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

	}

	void DeleteLastNode()
	{

		if (Head == NULL)
			return;


		if (Head->next == NULL) {

			delete Head;
			Head = NULL;
			return;
		}

		Node* Current = Head;

		// this loop will Get the node before the last node
		while (Current->next->next != NULL)
			Current = Current->next;

		Node* LastNode = Current->next;

		Current->next = NULL;

		delete LastNode;

	}


};