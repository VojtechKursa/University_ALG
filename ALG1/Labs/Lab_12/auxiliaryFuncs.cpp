#include "auxiliaryFuncs.h"

int random(int min, int max)
{
	return rand() % (max - min) + min;
}

void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void fillArr(int* arr, int n, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = random(min, max);
	}
}