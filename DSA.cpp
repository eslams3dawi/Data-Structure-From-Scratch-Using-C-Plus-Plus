#include <iostream>
using namespace std;

class ArrayList
{
private:
	int* Arr;
	int MaxSize;
	int Length;

public:
	ArrayList(int maxSize)
	{
		if (maxSize < 0)
			throw invalid_argument("Invalid Index");
		else
			MaxSize = maxSize;

		Length = 0;
		Arr = new int[MaxSize];
	}

	ArrayList() {}

	bool IsEmpty() // check
	{
		return Length == 0;
	}
	
	bool IsFull() // check
	{
		return Length == MaxSize;
	}

	int GetSize()
	{
		return Length;
	}

	void Print()
	{
		for (int Index = 0; Index < Length; Index++)
			cout << Arr[Index] << " ";
		
		cout << endl;
	}


	/*
	Insert 0   1   2   3   4   5   6
	       20  10  11  12  13  14     //insert at position (2) shift to right
	       20  10      11  12  13  14 
		 Arr[6] = Arr[5]		
		 Arr[5] = Arr[4]		
		 Arr[4] = Arr[3]		
		 Arr[3] = Arr[2]
		 Then Arr[i] = Arr[i-1]	
	*/	
	void InsertAt(int Position, int Element)
	{
		// start with shifting to right		
		if (IsFull())
			cout << "List is Full" << endl;
		else if (Position < 0 || Position > Length)
			cout << "Out Of Range" << endl;
		else
		{
			for (int Index = Length; Index > Position; Index--)
			{
				Arr[Index] = Arr[Index - 1];
			}
			Arr[Position] = Element; // then append
			Length++;
		}
	}


	//Remove 0   1   2   3   4   5   6
	//		 20  10  11  12  13  14     //remove at position (2) shift to left
	//	     20  10      12  13  14 // remove first 
	// then shift
	// Arr[2] = Arr[3]		
	// Arr[3] = Arr[4]		
	// Arr[4] = Arr[5]		
	// Arr[5] = Arr[6] → 14 in 5 will be null
	// Then Arr[i] = Arr[i-1]
	void RemoveAt(int Position)
	{
		if (IsEmpty())
			cout << "List is Empty";
		else if (Position < 0 || Position > Length)
			cout << "Out Of Range";
		else
		{
			for (int Index = Position; Index < Length; Index++)
			{
				Arr[Index] = Arr[Index + 1];
			}
			Length--;
		}
	}

	void InsertAtEnd(int Element)
	{
		if (IsFull())
			cout << "List is Full" << endl;
		else
			Arr[Length] = Element;
		Length++;
	}

	int Search(int Element) 
	{
		for (int Index = 0; Index < Length; Index++)
		{
			if (Arr[Index] == Element)
				return Index;
		}
		return -1;
	}

	void InsertWithNoDuplicate(int Element)
	{
		if (Search(Element) == -1)
			InsertAtEnd(Element);

		else
			cout << "Element " << Element << " is Already Exist" << endl;
 	}

	void Update(int Position, int NewValue)
	{
		if (Position < 0 || Position > Length)
			cout << "Out Of Range" << endl;
		else
			Arr[Position] = NewValue;
	}

	int GetElement(int Position)
	{
		if (Position < 0 || Position > Length)
			cout << "Out Of Range" << endl;
		else
			return Arr[Position];
	}

	~ArrayList()
	{
		delete[] Arr;
	}

	void Clear()
	{
		Length = 0;
	}
};	

void main()
{
	ArrayList List(100);

	List.InsertAt(0, 5);
	List.InsertAt(1, 10);
	List.InsertAt(2, 15);
	List.InsertAtEnd(20);
	List.InsertWithNoDuplicate(10);

	List.Update(2, 60);

	cout << List.GetElement(1);

	cout << List.GetSize();

	List.RemoveAt(0);

	List.Clear();

	List.Print();
}