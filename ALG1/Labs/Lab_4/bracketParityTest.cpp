#include "bracketParityTest.h"

char getPairBracket(char bracket)
{
	switch (bracket)
	{
	case '(': return ')';
	case '[': return ']';
	case '{': return '}';
	case '<': return '>';
	case ')': return '(';
	case ']': return '[';
	case '}': return '{';
	case '>': return '<';
	default: return 0;
	}
}

bool parityTestStack(string text)
{
	stack<char> braces;

	for (int i = 0; i < text.length(); i++)
	{
		switch (text[i])
		{
		case '(': braces.push('('); break;
		case '[': braces.push('['); break;
		case '{': braces.push('{'); break;
		case '<': braces.push('<'); break;
		case ')':
		case ']':
		case '}':
		case '>':
			if (braces.empty())
				return false;
			else
			{
				if (braces.top() == getPairBracket(text[i]))
					braces.pop();
				else
					return false;
			}
			break;
		}
	}

	return braces.empty();
}

bool parityTestCounter(string text)
{
	int i = 0;
	int depth1 = 0;
	int depth2 = 0;
	int depth3 = 0;

	for (int i = 0; i < text.length(); i++)
	{
		switch (text[i])
		{
		case '(':depth1++; break;
		case ')':depth1--; break;
		case '[':depth2++; break;
		case ']':depth2--; break;
		case '{':depth3++; break;
		case '}':depth3--; break;
		}

		if (depth1 < 0 || depth2 < 0 || depth3 < 0)
			return false;
	}

	return depth1 == 0 && depth2 == 0 && depth3 == 0;
}

void printResultParityTest(string text)
{
	cout << "\"" + text + "\" : " << (parityTestStack(text) ? "OK" : "Not OK") << endl;
}

void parityTestMain()
{
	printResultParityTest("dfh(dfhdfh(laspdo)asd)a");
	printResultParityTest("dfh(dfhdfh(laspdo))asd)a");
	printResultParityTest("dfh((dfhdfh(laspdo)asd)a");
	printResultParityTest("(()))(");
	printResultParityTest("()(())");
	printResultParityTest("()((");
	printResultParityTest("{[()][}");
	printResultParityTest("{[()][]}");
	printResultParityTest("{[()][]}{");
	printResultParityTest("[]{[()][]}{}()");
	printResultParityTest("{[}]");
}