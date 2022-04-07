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

bool BSTree::InternalContains(Node*& root, int value)
{
	if (root == nullptr)
		return false;

	if (root->value == value)
		return true;
	
	return InternalContains(value < root->value ? root->left : root->right, value);
}

bool BSTree::Contains(int value)
{
	return InternalContains(root, value);
}

void BSTree::InternalPrint(Node*& root, bool ascending)
{
	if (root != nullptr)
	{
		InternalPrint(ascending ? root->left : root->right, ascending);
		cout << root->value << endl;
		InternalPrint(ascending ? root->right : root->left, ascending);
	}
}

void BSTree::Print(bool ascending)
{
	InternalPrint(root, ascending);
}