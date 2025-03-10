#include <iostream>
using namespace std;

class LinkedList
{
	struct Node
	{
		int Item;
		Node* Next;
	};
	Node* Head;
	Node* Tail;
	int Length;

public:
	LinkedList()
	{
		Head = Tail = NULL;
		Length = 0;
	}

	bool IsEmpty()
	{
		return Length == 0; // or Head == NULL
	}

	void InsertFirst(int Element)
	{
		Node* NewNode = new Node;
		NewNode->Item = Element;

		if (IsEmpty())
		{
			Head = Tail = NewNode; //
			NewNode->Next = NULL;
		}
		else
		{
			NewNode->Next = Head;
			Head = NewNode;
		}
		Length++;
	}

	void InsertLast(int Element)
	{
		Node* NewNode = new Node;
		NewNode->Item = Element;

		if (IsEmpty())
		{
			Head = Tail = NewNode;
			NewNode->Next = NULL;
		}
		else
		{
			Tail->Next = NewNode; // 2 5 6 8
			//Tail = NewNode;
			NewNode->Next = NULL;
		}
		Length++;
	}

	void InsertAt(int Position, int Element)
	{
		if (Position < 0 || Position > Length)
			cout << "Out Of Range" << endl;

		else
		{
			Node* NewNode = new Node;
			NewNode->Item = Element;
			if (Position == 0)
				InsertFirst(Element);

			else if (Position == Length)
				InsertLast(Element);

			else
			{
				Node* Current = Head;
				for (int Index = 0; Index < Position; Index++)
				{
					Current = Current->Next; // reach the node of 22
				}
				NewNode->Next = Current->Next;
				// target position // current(2)→Next is (3) , and 3 is the target position
				Current->Next = NewNode;
				Length++;
			}
		}
	}

	void Update(int Position, int NewValue)
	{
		if (Position < 0 || Position > Length)
		{
			cout << "Out Of Range" << endl;
		}
		else
		{
			Node* Current = Head;
			for (int Index = 0; Index < Position; Index++)
			{
				Current = Current->Next;
			}
			Current->Item = NewValue;
		}
	}
	
	void Reverse()
	{
		Node* Previous = NULL;
		Node* Current = Head;
		Node* Next = new Node;
	
		for (int Index = 0; Index < Length; Index++)
		{
			Next = Current->Next;
			Current->Next = Previous;
			Previous = Current;
			Current = Next;
		}
		Head = Previous;
	}
	
	int Search(int Target)
	{
		Node* Current = Head;
		for (int Index = 0; Index < Length; Index++)
		{
			if (Target == Current->Item)
			{
				return Index;
			}
			Current = Current->Next;
		}
		return -1;
	}
	
	void RemoveFirst()
	{
		if (IsEmpty())
		{
			cout << "List is Already Empty" << endl;
		}
		else if (Length == 1)
		{
			delete Head;
			Head = Tail = NULL;
			Length--;
		}
		else
		{
			Node* Current = Head; // 100 150 200 250
			Head = Head->Next; // Make Head set to the second index before deleting the Current(First Index)
			delete Current;
			Length--;
		}
	}
	
	void RemoveLast()
	{
		if (IsEmpty()) // 100 150 200 250 → remove 250
		{
			cout << "List is Already Empty" << endl;
		}
		else if (Length == 0)
		{
			delete Head;
			Head = Tail = NULL;
		}
		else
		{
			Node* Current = Head->Next;
			Node* Previous = Head;
			while (Current != Tail)
			{
				Previous = Current;
				Current = Current->Next;
			}
			delete Current;
			Tail = Previous;
			Previous->Next = NULL;
			Length--;
		}
	}
	
	void RemoveKey(int Element) // 100 150 200 250 → remove index 2 : 150
	{
		if (IsEmpty())
		{
			cout << "List is Already Empty" << endl;
		}
		else if (Element == Head->Item)
			RemoveFirst();
	
		else if (Element == Tail->Item)
			RemoveLast();
		else
		{
			Node* Current = Head->Next;
			Node* Previous = Head;
			while (Current != NULL)
			{
				if (Current->Item == Element)
				{
					break;
				}
				Previous = Current;
				Current = Current->Next;
			}
			if (Current == NULL)
			{
				cout << "Element Not Found" << endl;
			}
			else
			{
				Previous->Next = Current->Next;
				delete Current;
			}
			Length--;
		}
	}
	
	void RemoveAt(int Position)
	{
		if (IsEmpty())
			cout << "List is Already Empty" << endl;
	
		else if (Position < 0 || Position > Length)
			cout << "Out Of Range" << endl;
	
		else if (Position == 0)
			RemoveFirst();
	
		else if (Position == Length - 1)
			RemoveLast();
	
		else
		{
			Node* Current = Head->Next;
			Node* Previous = Head;
	
			for (int Index = 1; Index < Position; Index++)
			{
				Previous = Current;
				Current = Current->Next;
			}
			Previous->Next = Current->Next;
			delete Current;
			Length--;
		}
	}

	void Display()
	{
		Node* Current = new Node;
		Current = Head;
		while (Current != NULL)
		{
			cout << Current->Item << " ";
			Current = Current->Next;
		}
	}
};



void main()
{
	LinkedList l;
	l.InsertLast(10);
	l.InsertLast(50);
	l.InsertLast(60);
	l.InsertFirst(2);

	l.Display();
}




















//template <class T>
//class LinkedList
//{
//public:
//	struct Node
//	{
//		T Data;
//		Node *Next;
//	};
//	Node* Head, *Tail, *Current;
//
//	LinkedList()
//	{
//		Head = Tail = Current = NULL;
//	}
//
//
//
//	bool IsEmpty()
//	{
//		return Head == NULL;
//	}
//
//	void InsertFirst(T Element)
//	{
//		Node* NewNode = new Node;
//		NewNode->Data = Element;
//		if (IsEmpty())
//		{
//			Head = Tail = NewNode;
//			NewNode->Next = NULL;
//		}
//		else
//		{
//			Head = NewNode;
//			NewNode->Next = Head;
//		}
//	}
//
//
//	void Display()
//	{
//		Current = Head;
//		while (Current != NULL)
//		{
//			cout << Current->Data << " ";
//			Current = Current->Next;
//		}
//		cout << endl;
//	}
//};