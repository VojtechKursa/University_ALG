#include "sorts.h"

#pragma region BubbleSorts

void bubbleSort(int* arr, int length)
{
	for (int l = 0; l < length; l++)
	{
		for (int k = 0; k < length - 1; k++)
		{
			if (arr[k] > arr[k + 1])
			{
				swap(arr[k], arr[k + 1]);
			}
		}
	}
}

void bubbleSortWithCheck(int* arr, int length)
{
	bool swapHappened;

	for (int l = 0; l < length; l++)
	{
		swapHappened = false;

		for (int k = 0; k < length - 1; k++)
		{
			if (arr[k] > arr[k + 1])
			{
				swap(arr[k], arr[k + 1]);

				swapHappened = true;
			}
		}

		if (!swapHappened)
			break;
	}
}

void bubbleSortWithLock(int* arr, int length)
{
	for (int l = length; l > 0; l--)
	{
		for (int k = 0; k < l - 1; k++)
		{
			if (arr[k] > arr[k + 1])
			{
				swap(arr[k], arr[k + 1]);
			}
		}
	}
}

void bubbleSortWithLockAndCheck(int* arr, int length)
{
	bool swapHappened;

	for (int l = length; l > 0; l--)
	{
		swapHappened = false;

		for (int k = 0; k < l - 1; k++)
		{
			if (arr[k] > arr[k + 1])
			{
				swap(arr[k], arr[k + 1]);

				swapHappened = true;
			}
		}

		if (!swapHappened)
			break;
	}
}

#pragma endregion

void shakerSort(int* arr, int length)
{
	int lowLock = 0;
	int highLock = length;

	while (lowLock < highLock)
	{
		for (int i = lowLock; i < highLock - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
		}

		highLock--;

		for (int i = highLock; i > lowLock; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
			}
		}

		lowLock++;
	}
}

void selectSort(int* arr, int length)
{
	int min, minIndex;

	for (int l = 0; l < length; l++)
	{
		min = arr[l];
		minIndex = l;

		for (int k = l + 1; k < length; k++)
		{
			if (arr[k] < min)
			{
				minIndex = k;
				min = arr[k];
			}
		}

		swap(arr[l], arr[minIndex]);
	}
}