#include <iostream>

using namespace std;

void fillArr(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = i;
	}
}

int sumArr(int* arr, int length)
{
	int sum = 0;

	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int sumArr_alt1(int* arr, int length)
{
	return (int)((arr[0] + arr[length - 1]) * (length / (double)2));
}

bool hasDuplicities(int* arr, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int x = i + 1; x < length; x++)
		{
			if (arr[x] == arr[i])
				return true;
		}
	}

	return false;
}

bool isAnagram(char* text1, char* text2)
{
	int* text1Letters[26], * text2Letters[26];

	int i = 0;
	while (text1[i] != 0)
	{
		if (text1[i] > 'A' && text1[i] < 'Z')
			text1Letters[text1[i] - 'A']++;
		else if (text1[i] > 'a' && text1[i] < 'z')
			text1Letters[text1[i] - 'a']++;

		i++;
	}

	i = 0;
	while (text2[i] != 0)
	{
		if (text2[i] > 'A' && text2[i] < 'Z')
			text2Letters[text2[i] - 'A']++;
		else if (text2[i] > 'a' && text2[i] < 'z')
			text2Letters[text2[i] - 'a']++;

		i++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (text1Letters[i] != text2Letters[i])
			return false;
	}

	return true;
}

int main(void)
{
	int length = 10;
	int* arr = new int[length];

	fillArr(arr, length);

	cout << sumArr(arr, length) << endl;
	cout << sumArr_alt1(arr, length) << endl;

	cout << hasDuplicities(arr, length) << endl;
	arr[5] = 4;
	cout << hasDuplicities(arr, length) << endl;

	char str1[] = "kaigi";
	char str2[] = "gikai";

	cout << isAnagram(str1, str2) << endl;

	delete[] arr;

	return 0;
}