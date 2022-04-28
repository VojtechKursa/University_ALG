#include "quickSort.h"

int partition(int* arr, int l, int r)
{
	int i = l;
	int temp;

	for (int j = l; j < r; j++)
	{
		if (arr[j] < arr[r])
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
		}
	}

	temp = arr[i];
	arr[i] = arr[r];
	arr[r] = temp;

	return i;
}

void quickSortRec(int* arr, int l, int r)
{
	if (r < l)
		return;

	int pivot_index = partition(arr, l, r);

	quickSortRec(arr, l, pivot_index - 1);
	quickSortRec(arr, pivot_index + 1, r);
}

void quickSort(int* arr, int n)
{
	quickSortRec(arr, 0, n - 1);
}