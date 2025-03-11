#include <iostream>
using namespace std;

class Node
{
public:
	int Data;
	Node* Left;
	Node* Right;

	Node(int Element) : Data(Element), Left(NULL), Right(NULL) {}
};

class BSTR
{
public:
	Node* Root;
	BSTR() : Root(NULL) {}
	
	Node* InsertNode(Node* PNode, int Element)
	{
		if (PNode == NULL)
		{
			Node* NewNode = new Node(Element);
			PNode = NewNode;
		}
		else
		{
			if (Element <= PNode->Data)
			{
				PNode->Left = InsertNode(PNode->Left, Element);
			}
			else
			{
				PNode->Right = InsertNode(PNode->Right, Element);
			}
		}
		return PNode;
	}
	void Insert(int Element)
	{
		Root = InsertNode(Root, Element);
	}

	//traverse 
	//preorder → Root left right
	//inorder → left Root right
	//postorder → left right Root

	void PreOrder(Node* PNode)
	{
		if (PNode == NULL)
		{
			return;
		}
		else
		{
			cout << PNode->Data << " ";
			PreOrder(PNode->Left);
			PreOrder(PNode->Right);
		}
	}
	void InOrder(Node* PNode)
	{
		if (PNode == NULL)
		{
			return;
		}
		else
		{
			InOrder(PNode->Left);
			cout << PNode->Data << " ";
			InOrder(PNode->Right);
		}
	}
	void PostOrder(Node* PNode)
	{
		if (PNode == NULL)
		{
			return;
		}
		else
		{
			PostOrder(PNode->Left);
			PostOrder(PNode->Right);
			cout << PNode->Data << " ";
		}
	}
};


void main()
{
	int CountNumbers;
	int Value;
	BSTR BinaryTree;
	cout << "How many numbers ? ";
	cin >> CountNumbers;
	cout << "Enter the values : ";
	for (int Index = 0; Index < CountNumbers; Index++)
	{
		cin >> Value;
		BinaryTree.Insert(Value);
	}
	BinaryTree.PreOrder(BinaryTree.Root);
}
