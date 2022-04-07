#pragma once

#include <iostream>

using namespace std;

class BSTree
{
private:
	class Node
	{
	public:
		int value;
		Node* left = nullptr;
		Node* right = nullptr;

		Node(int value)
		{
			this->value = value;
		}
	};

	Node* root = nullptr;

	void InternalInsert(Node*& root, int value);
	bool InternalContains(Node*& root, int value);
	void InternalPrint(Node*& root, bool ascending);

public:
	void Insert(int value);
	bool Contains(int value);

	void Print(bool ascending);
};

