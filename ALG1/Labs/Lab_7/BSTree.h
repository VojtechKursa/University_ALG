#pragma once

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

public:
	void Insert(int value);
};

