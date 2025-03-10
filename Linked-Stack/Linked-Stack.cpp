#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
	struct Node
	{
		T Data;
		Node *Next;
	};
	Node *StackTop, *Current;

public:
	Stack()
	{
		StackTop = NULL;
		Current = NULL;
	}

	bool IsEmpty()
	{
		return StackTop == NULL;
	}

	void Push(T Element)
	{
		Node* NewNode = new Node;
								 // 2
		NewNode->Data = Element; // 1 
		if (IsEmpty())
			NewNode->Next = NULL;
		else
			NewNode->Next = StackTop;
		
		StackTop = NewNode;
	}

	void Pop()
	{
		if (IsEmpty())
			cout << "Stack Is Already Empty" << endl;

		else
		{
			Node *Temp = StackTop;
			StackTop = StackTop->Next;
			Temp = Temp->Next = NULL;
			delete Temp;
		}
	}

	T Pop(T& StackTopValue)
	{
		if (IsEmpty())
			cout << "Stack Is Already Empty" << endl;

		else
		{
			StackTopValue = StackTop->Data;
			Node *Temp = StackTop;
			StackTop = StackTop->Next;
			delete Temp;
		}
		return StackTopValue;
	}

	T Peek()
	{
		if (IsEmpty())
			cout << "Stack Is Empty" << endl;
		else
			return StackTop->Data;
	}

	void Display()
	{
		Current = StackTop;
		while (Current != NULL)
		{
			cout << Current->Data << endl;
			Current = Current->Next;
		}
		cout << endl;
	}

	int Count()
	{
		int count = 0;
		Current = StackTop;
		while (Current!=NULL)
		{
			count++;
			Current = Current->Next;
		}
		return count;
	}
};

int main()
{
	Stack<int> StackOne;
	StackOne.Push(100);
	StackOne.Push(150);
	//cout << StackOne.Peek() << endl;
	//StackOne.Pop();
	//int StackTopValue = 0;
	//cout << StackOne.Pop(StackTopValue) << endl;
	//cout << StackTopValue;
	//cout << StackOne.Peek() << endl;

	cout << StackOne.Count() << endl;

	//StackOne.Display();
}
