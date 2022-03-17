#include <iostream>
#include <stack>
#include <string>

using namespace std;

//Hanoi Towers
class Towers
{
private:
	stack<int> from, to, aux;
	int diskCount;
	unsigned long stepCount = 0;

	void MoveDisk(stack<int>& source, stack<int>& dst)
	{
		dst.push(source.top());
		source.pop();
	}

	void InternalSolveRec(int n, stack<int>& from, stack<int>& to, stack<int>& aux, bool printSteps)
	{
		if (n <= 0)
			return;

		InternalSolveRec(n - 1, from, aux, to, printSteps);

		MoveDisk(from, to);
		if (printSteps)
			Print();

		InternalSolveRec(n - 1, aux, to, from, printSteps);

		stepCount++;
	}

public:
	Towers(int diskCount)
	{
		this->diskCount = diskCount;

		for (int i = diskCount; i > 0; i--)
			from.push(i);
	}

	unsigned long SolveRec(bool printSteps)
	{
		InternalSolveRec(diskCount, from, to, aux, printSteps);

		return stepCount;
	}

	void Print()
	{
		stack<int> fromAux = from;
		stack<int> auxAux = aux;
		stack<int> toAux = to;

		int fromSize = from.size();
		int toSize = to.size();
		int auxSize = aux.size();

		int highest = max(max(fromSize, toSize), auxSize);

		string res;
		for (int i = highest; i > 0; i--)
		{
			res = "";

			if (i <= fromSize)
			{
				res += to_string(fromAux.top());
				fromAux.pop();
			}
			else
				res += "|";

			res += "\t";

			if (i <= auxSize)
			{
				res += to_string(auxAux.top());
				auxAux.pop();
			}
			else
				res += "|";

			res += "\t";

			if (i <= toSize)
			{
				res += to_string(toAux.top());
				toAux.pop();
			}
			else
				res += "|";

			res += "\n";

			cout << res;
		}

		cout << endl;
	}
};

int factorial(int n)
{
	return n <= 1 ? 1 : n * factorial(n - 1);
}

int factorialIterative(int n)
{
	int fact = 1;

	for (int i = n; i > 0; i--)
	{
		fact *= i;
	}

	return fact;
}

int main()
{
	cout << factorial(0) << endl;
	cout << factorialIterative(0) << endl;
	cout << factorial(1) << endl;
	cout << factorialIterative(1) << endl;
	cout << factorial(5) << endl;
	cout << factorialIterative(5) << endl;

	Towers t(20);

	t.Print();
	cout << "Step count: " + to_string(t.SolveRec(false)) + "\n";
	t.Print();

	return 0;
}