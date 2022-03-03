#include "gcd.h"

int gcd(int a, int b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}

	return a | b;
}

int gcdRecursive(int a, int b)
{
	if (b == 0) return b;

	gcdRecursive(b, a % b);
}

void gcdMain(void)
{
	cout << gcd(6, 3) << endl;
	cout << gcd(60, 12) << endl;
	cout << gcd(6, 1) << endl;
	cout << gcd(6, 5) << endl;
}