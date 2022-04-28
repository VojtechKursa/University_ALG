#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include <list>

#include "auxiliaryFuncs.h"
#include "quickSort.h"
#include "greyCodes.h"

using namespace std;

int main_quickSort(void)
{
	int min = 0;
	int max = 100;
	const int arrLength = 100;

	srand(time(NULL));

	int arr[arrLength];
	fillArr(arr, arrLength, min, max);
	printArr(arr, arrLength);

	quickSort(arr, arrLength);

	printArr(arr, arrLength);


	return 0;
}

int main_greyCodes(void)
{
	int n = 3;
	list<string> L = BRGC(n);

	for (auto str : L)
	{
		cout << str << endl;
	}

	return 0;
}

int main(void)
{
	main_quickSort();
	cout << endl;
	main_greyCodes();


	return 0;
}