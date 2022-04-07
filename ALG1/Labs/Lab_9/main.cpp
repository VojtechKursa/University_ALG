#include <iostream>
#include <vector>
#include "BSTree.h"
#include "Graph.h"

using namespace std;

int main(void)
{
	BSTree* tree = new BSTree();

	tree->Insert(3);
	tree->Insert(5);
	tree->Insert(4);
	tree->Insert(2);
	tree->Insert(1);

	cout << tree->Contains(1) << endl;
	cout << tree->Contains(2) << endl;
	cout << tree->Contains(3) << endl;
	cout << tree->Contains(4) << endl;
	cout << tree->Contains(5) << endl;
	cout << tree->Contains(6) << endl;

	tree->Print(true);
	tree->Print(false);

	delete tree;
	tree = nullptr;

	Graph graph;
	vector<int> neighbors;

	graph.Insert(0, neighbors);
	graph.Insert(1, neighbors);
	graph.Insert(2, neighbors);

	neighbors.push_back(0);
	neighbors.push_back(1);
	neighbors.push_back(2);
	graph.Insert(3, neighbors);

	neighbors.clear();
	neighbors.push_back(1);
	neighbors.push_back(3);
	graph.Insert(4, neighbors);

	return 0;
}