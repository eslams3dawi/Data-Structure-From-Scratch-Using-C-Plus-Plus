#include <iostream>
using namespace std;

const int MaxSize = 100;
template <class T>
class Stack
{
private:
	int top;
	T item[MaxSize];

public:
	Stack()
	{
		top = -1;
	}

	bool IsFull()
	{
		return top == MaxSize - 1;
	}

	bool IsEmpty()
	{
		return top == -1;
	}

	void Push(T Element)
	{
		if (IsFull())
			cout << "Can Not Add, Stack Is Full" << endl;
		else
		{
			top++;
			item[top] = Element;
		}
	}

	void Pop() // remove without recover to the top
	{
		if (IsEmpty())
			cout << "Can Not Remove, Stack Is Empty" << endl;
		else
			top--;
	}

	void Pop(T& Element) // remove with recover the top
	{
		if (IsEmpty())
			cout << "Can Not Remove, Stack Is Empty" << endl;
		else
		{
			Element = item[top];
			top--;
		}
	}

	T GetTop(T& StackTop) 
	{
		if (IsEmpty())
			cout << "Stack Is Empty" << endl;
		else
		{
			StackTop = item[top];
			return StackTop;
		}
	}

	void Display()
	{
		if (IsEmpty())
			cout << "Stack Is Empty" << endl;
		for (int Index = top; Index >= 0; Index--)
		{
			cout << item[Index] << endl;
		}	
	}
};

int main()
{   
	Stack<int> StackOne;
	//StackOne.Push(5);
	//StackOne.Push(10);
	//StackOne.Push(15);
	//StackOne.Pop();
	//StackOne.Push(20);

	//int StackTopI = 0;
	//cout << StackOne.GetTop(StackTop) << endl;
	StackOne.Display();

	cout << "------------------" << endl;

	Stack<char> StackTwo;
	StackTwo.Push('A');
	StackTwo.Push('B');
	StackTwo.Push('C');

	//char StackTopC = 0;
	//cout << StackOne.GetTop(StackTop) << endl;
	StackTwo.Display();
}
