#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "sorts.h"
#include "BSTree.h"

using namespace std;

bool isSorted(int* arr, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

void initArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand();
	}
}

void printArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}
}

void mainSorts(void)
{
	srand((int)time(nullptr));

	const int length = 50000;
	int* arr = new int[length];
	initArray(arr, length);

	cout << isSorted(arr, length) << endl;

	time_t startTime = time(nullptr);
	selectSort(arr, length);
	time_t endTime = time(nullptr);

	cout << isSorted(arr, length) << endl;
	cout << "Elapsed time: " << (endTime - startTime) << " s" << endl;

	//printArray(arr, length);

	delete[] arr;
}

void mainTree(void)
{
	BSTree tree;

	tree.Insert(10);
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(7);
	tree.Insert(20);
	tree.Insert(15);
	tree.Insert(30);
	//tree.Insert(8);
	//tree.Insert(8);
}

int main(void)
{
	//mainSorts();
	mainTree();

	return 0;
}