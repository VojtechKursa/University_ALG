#include <iostream>
#include <stdlib.h>

using namespace std;

struct Stack
{
	int top = -1;
	int capacity;
	int* data = nullptr;

	void push(int value)
	{
		if (top + 1 < capacity)
			data[++top] = value;
		else
		{
			cout << "Stack overflow!" << endl;
			exit(1);
		}
	}

	int pop()
	{
		if (top > -1)
			return data[top--];
		else
		{
			cout << "Stack underflow!" << endl;
			exit(1);
		}
	}

	Stack(int capacity = 3)
	{
		this->capacity = capacity;
		this->data = new int[capacity];
	}

	~Stack()
	{
		delete[] data;
	}
};

int main(void)
{
	Stack stack;

	cout << stack.capacity << endl;

	stack.push(1);
	stack.push(5);
	stack.push(6);

	cout << stack.pop() << endl;
	cout << stack.pop() << endl;

	stack.push(3);


	return 0;
}