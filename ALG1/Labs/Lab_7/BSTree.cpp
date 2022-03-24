#include "BSTree.h"

void BSTree::Insert(int value)
{
	InternalInsert(this->root, value);
}

void BSTree::InternalInsert(Node*& root, int value)
{
	if (root == nullptr)
	{
		root = new Node(value);
		return;
	}

	InternalInsert(value < root->value ? root->left : root->right, value);
}