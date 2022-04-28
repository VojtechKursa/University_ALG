#include "greyCodes.h"

list<string> BRGC(int n)
{
	if (n == 1)
	{
		list<string> L;
		L.push_back("0");
		L.push_back("1");
		return L;
	}
	else
	{
		list<string> L1 = BRGC(n - 1);
		list<string> L2 = L1;
		L2.reverse();

		for (auto& str : L1)
		{
			str.insert(0, 1, '0');
		}

		for (auto& str : L2)
		{
			str.insert(0, 1, '1');
		}

		L1.splice(L1.end(), L2);

		return L1;
	}
}