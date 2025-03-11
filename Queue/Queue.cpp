#include <iostream>
using namespace std;

class MyQueue 
{
    int* QueueArray;
    int Rear, Front, MaxSize, Length;

public:
    MyQueue(int InputSize)
    {
        MaxSize = (InputSize > 0) ? InputSize : 20;

        QueueArray = new int[MaxSize];
        Front = Rear = -1;
        Length = 0;
    }

    bool IsFull()
    {
        return Length == MaxSize;
    }
    bool IsEmpty()
    {
        return Length == 0;
    }

    void Enqueue(int Element)
    {
        if (IsFull())
            cout << "The array is full" << endl;
        else if (IsEmpty()) 
            Front = Rear = 0;
        else
            Rear = (Rear + 1) % MaxSize;

        QueueArray[Rear] = Element;
        Length++;
    }
    void Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Array is already empty" << endl;
            return;
        }
        if (Length == 1)
            Front = Rear = -1;
        else
            Front = (Front + 1) % MaxSize;

        Length--;
    }

    int GetFront()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return QueueArray[Front];
    }

    int GetRear()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return QueueArray[Rear];
    }

    void Clear()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        while (!IsEmpty())
        {
            Dequeue();
        }
    }

    bool Search(int Target)
    {
        if (IsEmpty())
            return -1;
        else
        {
            for (int Index = Front; Index != Rear + 1; Index++)
            {
                if (Target == QueueArray[Index])
                {
                    return Index;
                }
            }
        }
        return -1;
    }

    void Traverse()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int Index = Front; Index != Rear + 1; Index++)
        {
            cout << QueueArray[Index] << " ";
        }
        cout << endl;
    }
};

void Menu()
{
    cout << "[1] Enqueue " << endl;
    cout << "[2] Dequeue " << endl;
    cout << "[3] Search " << endl;
    cout << "[4] Clear " << endl;
    cout << "[5] Get the front " << endl;
    cout << "[6] Get the rear " << endl;
    cout << "[7] Display " << endl;
    cout << "[0] Exit " << endl;
}

int main()
{
    cout << "How many elements of your queue : ";
    int InputSize;
    cin >> InputSize;
    MyQueue QueueOne(InputSize);

    while (true)
    {
        Menu();
        cout << "Please, choose an option : ";
        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter the value : ";
            int InputValue;
            cin >> InputValue;
            QueueOne.Enqueue(InputValue);
            break;
        case 2:
            QueueOne.Dequeue();
            break;
        case 3:
            cout << "Please, enter the target value : ";
            int InputTarget;
            cin >> InputTarget;
            if (QueueOne.Search(InputTarget) != -1)
                cout << "The value " << InputTarget << " is found" << endl;
            else
                cout << "The value " << InputTarget << " is not found" << endl;
            break;
        case 4:
            QueueOne.Clear();
            cout << "Queue is cleared successfully " << endl;
            break;
        case 5:
            cout << QueueOne.GetFront() << endl;
            break;
        case 6:
            cout << QueueOne.GetRear() << endl;
            break;
        case 7:
            QueueOne.Traverse();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid option, please try again " << endl;
            break;
        }
    }
}



/** \brief
MyQueue Queue(5);
Queue.Enqueue(10);
Queue.Enqueue(20);
Queue.Enqueue(30);
Queue.Enqueue(40);
// Queue.Dequeue();
//Queue.Clear();
 cout << Queue.Search(10) << endl;
 cout << Queue.Search(50) << endl;
 cout << Queue.GetFront() << endl;
 cout << Queue.GetRear() << endl;

 Queue.Traverse();
  */























































//#include <iostream>
//using namespace std;
//
//class MyQueue
//{
//	int Rear, Front, Length, MAX_size;
//	int *ArrQueue;
// 
//public:
//	MyQueue(int Size)
//	{
//		if (Size <= 0)
//			MAX_size = 100;
//		else
//		 	MAX_size = Size;
//		ArrQueue = new int[MAX_size];
//		Rear = MAX_size - 1;
//		Front = 0;
//		Length = 0;
//	}
//	bool IsEmpty()
//	{
//		return Length == 0;
//	}
//	bool IsFull()
//	{
//		return Length == MAX_size;
//	}
//	void Enqueue(int Element)
//	{
//		if (IsFull())
//			cout << "Queue is full" << endl;
//		else 
//		{
//			Rear = (Rear + 1) % MAX_size;
//			ArrQueue[Rear] = Element;
//			Length++;
//		}
//	}
//	void Dequeue()
//	{
//		if (IsEmpty())
//			cout << "Queue is empty" << endl;
//		else
//		{
//			Front = (Front + 1) % MAX_size;
//			Length--;
//		}
//	}
//	int GetFront()
//	{
//		if (IsEmpty())
//			cout << "Queue is empty" << endl;
//		else
//			return ArrQueue[Front];
//	}
//	int GetRear()
//	{
//		if (IsEmpty())
//			cout << "Queue is empty" << endl;
//		else
//			return ArrQueue[Rear];
//	}
//	void Traverse()
//	{
//		for (int Index = Front; Index != Rear + 1; Index = (Index + 1) % MAX_size)
//		{
//			cout << ArrQueue[Index] << " ";
//		}
//		cout << endl;
//	}
//	void Clear()
//	{
//		while (!IsEmpty())
//		{
//			Dequeue();
//		}
//	}
//	int Search(int Target)
//	{
//		int position = -1;
//		if (IsEmpty())
//			cout << "Queue is empty" << endl;
//		else
//		{
//			for (int Index = Front; Index != Rear + 1; Index = (Index + 1) % MAX_size)
//			{
//				if (ArrQueue[Index] == Target)
//				{
//					position = Index;
//					break;
//				}
//			}
//			return position;
//		}
//	}
//};
//
//
//void Menu()
//{
//	cout << "[1] Enqueue " << endl;
//	cout << "[2] Dequeue " << endl;
//	cout << "[3] Search " << endl;
//	cout << "[4] Clear " << endl;
//	cout << "[5] Get the front " << endl;
//	cout << "[6] Get the rear " << endl;
//	cout << "[7] Display " << endl;
//	cout << "[0] Exit " << endl;
//}
//
//int main()
//{
//	/** \brief
//	MyQueue Queue(5);
//	Queue.Enqueue(10);
//	Queue.Enqueue(20);
//	Queue.Enqueue(30);
//	Queue.Enqueue(40);
//   // Queue.Dequeue();
//   //Queue.Clear();
//	cout << Queue.Search(10) << endl;
//	cout << Queue.Search(50) << endl;
//	cout << Queue.GetFront() << endl;
//	cout << Queue.GetRear() << endl;
//
//	Queue.Traverse();
//	 */
//
//
//
//	cout << "How many elements of your queue : ";
//	int InputSize;
//	cin >> InputSize;
//	MyQueue QueueOne(InputSize);
//
//	while (true)
//	{
//		Menu();
//		cout << "Please, choose an option : ";
//		int option;
//		cin >> option;
//
//		switch (option)
//		{
//		case 1:
//			cout << "Enter the value : ";
//			int InputValue;
//			cin >> InputValue;
//			QueueOne.Enqueue(InputValue);
//			break;
//		case 2:
//			QueueOne.Dequeue();
//			break;
//		case 3:
//			cout << "Please, enter the target value : ";
//			int InputTarget;
//			cin >> InputTarget;
//			if (QueueOne.Search(InputTarget) != -1)
//				cout << "The value " << InputTarget << " is found" << endl;
//			else
//				cout << "The value " << InputTarget << " is not found" << endl;
//			break;
//		case 4:
//			QueueOne.Clear();
//			cout << "Queue is cleared successfully " << endl;
//			break;
//		case 5:
//			cout << QueueOne.GetFront() << endl;
//			break;
//		case 6:
//			cout << QueueOne.GetRear() << endl;
//			break;
//		case 7:
//			QueueOne.Traverse();
//			break;
//		case 0:
//			return 0;
//		default:
//			cout << "Invalid option, please try again " << endl;
//			break;
//		}
//	}
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////class Queue
////{
////public:
////	struct Node
////	{
////		int Data;
////		Node* Next;
////	};
////	Node* Front = new Node;
////	Node* Back = new Node;
////	Queue()
////	{
////		Front = Back = NULL;
////	}
////
////	bool IsEmpty()
////	{
////		return Back == NULL; // 1 6 8 9
////	}
////
////	void Enqueue(int Element)
////	{
////		Node* NewNode = new Node;
////		NewNode->Data = Element;
////		if (IsEmpty())
////		{
////			Front = Back = NewNode;
////			NewNode->Next = NULL;
////		}
////		else if (// has one element)
////			{
////
////			}
////		else
////		{
////			NewNode->Next = Back;
////			Back = NewNode;
////		}
////	}
////
////	void Display()
////	{
////		Node* Current = Front; // 1 5 7 0
////		while (Current != NULL)
////		{
////			cout << Current->Data << " ";
////			Current = Current->Next;
////		}
////	}
////};
