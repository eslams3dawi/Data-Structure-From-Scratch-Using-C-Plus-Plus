#include <iostream>
using namespace std;

class LinkedQueue
{
public:
	struct Node
	{
		int Data;
		Node *Next;
	};
	Node* Front, * Rear;
	LinkedQueue()
	{
		Front = Rear = NULL;
	}
	bool IsEmpty()
	{
		return Front == NULL && Rear == NULL;
	}
	void Enqueue(int Element)
	{
		Node* NewNode = new Node;
		NewNode->Data = Element;
		NewNode->Next = NULL;
		if (IsEmpty())
		{
			Front = Rear = NewNode;
		}
		else
		{
			Rear->Next = NewNode;
			Rear = NewNode;
		}
	}
	void Dequeue()
	{
		if (IsEmpty())
			cout << "Queue is empty" << endl;
		else
		{
			Node* Temp = Front;
			Front = Front->Next;
			delete Temp;

			if (Front == NULL)
				Rear = NULL;
		}
	}
	void Traverse()
	{
		Node* Current = Front;
		while (Current != NULL)
		{
			cout << Current->Data << " ";
			Current = Current->Next;
		}
		cout << endl;
	}
	void Clear()
	{
		while (!IsEmpty())
		{
			Dequeue();
		}
	}
};

void main()
{
	LinkedQueue Queue1;
	Queue1.Enqueue(10);
	Queue1.Enqueue(20);
	Queue1.Enqueue(30);
	Queue1.Enqueue(100);
	Queue1.Dequeue();
	Queue1.Dequeue();
	Queue1.Clear();
	Queue1.Traverse();
}