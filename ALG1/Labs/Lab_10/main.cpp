#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

void printArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "  ";
	}

	cout << endl;
}

void insertionSort(int* arr, int len)
{
	int backup, j;
	for (int i = 1; i < len; i++)
	{
		backup = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > backup)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = backup;

		printArr(arr, len);
	}
}

bool binarySearchIterative(int* arr, int len, int value)	// Binary search needs a sorted collection to work
{
	int l = 0;
	int r = len - 1;
	int m;

	while (l <= r)
	{
		m = (l + r) / 2;

		if (arr[m] == value)
			return true;

		if (value < arr[m])
			r = m - 1;
		else
			l = m + 1;
	}

	return false;
}

bool binarySearchRecursivePrivate(int* arr, int value, int l, int r)
{
	if (l > r)
		return false;


	int m = (l + r) / 2;

	if (arr[m] == value)
		return true;

	if (value < arr[m])
		return binarySearchRecursivePrivate(arr, value, l, m - 1);
	else
		return binarySearchRecursivePrivate(arr, value, m + 1, r);
}

bool binarySearchRecursive(int* arr, int len, int value)
{
	return binarySearchRecursivePrivate(arr, value, 0, len - 1);
}

int main(void)
{
	// Průchod grafem
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

	cout << graph.Contains_BFS(4) << endl;
	cout << graph.Contains_BFS(5) << endl;
	cout << graph.Contains_DFS(4) << endl;
	cout << graph.Contains_DFS(5) << endl;



	// Insertion sort
	int arr[11] = { 10,8,5,1,4,15,2,1,9,0,50 };
	printArr(arr, 11);
	insertionSort(arr, 11);
	printArr(arr, 11);



	// Binary search
	cout << 4 << ": " << binarySearchIterative(arr, 11, 4) << endl;
	cout << 1 << ": " << binarySearchIterative(arr, 11, 1) << endl;
	cout << 12 << ": " << binarySearchIterative(arr, 11, 12) << endl;
	cout << 4 << ": " << binarySearchRecursive(arr, 11, 4) << endl;
	cout << 1 << ": " << binarySearchRecursive(arr, 11, 1) << endl;
	cout << 12 << ": " << binarySearchRecursive(arr, 11, 12) << endl;


	return 0;
}