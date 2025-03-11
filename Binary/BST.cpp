#include <iostream>
using namespace std;

class Node
{
public:
	int Data;
	Node* Right;
	Node* Left;

	Node() : Data(0), Right(NULL), Left(NULL) {}
	Node(int Element) : Data(Element), Right(NULL), Left(NULL) {}
};

class BST
{
public:
#pragma region explain
	/*Pnode is a pointer points to the tree that you want to insert into it
* Insert() {
	1- check if the PNode is null → empty tree
		PNode = NewNode;
	2- else
	{ begin recurion
				compare NewNode to Root
				if(NewNode < Root)
					insert left
					PNode->Left = NewNode
				else if(NewNode >= Root)
					insert right
					PNode->Right = NewNode;
									  end recurion }
			}*/
#pragma endregion
	Node* Root;
	BST() : Root(NULL) {}

	Node* InsertNode(Node* PNode, int Element)// 10 8 2 14 
	{
		if (PNode == NULL)
		{
			Node* NewNode = new Node(Element);
			PNode = NewNode;
		}
		else
		{
			if (Element < PNode->Data)
				PNode->Left = InsertNode(PNode->Left, Element);

			else
				PNode->Right = InsertNode(PNode->Right, Element);
		}
		return PNode;
	}
	void Insert(int Element)
	{
		Root = InsertNode(Root, Element);
	}
	void PreOrder(Node* PNode)// Root → Left → Right
	{
		if (PNode == NULL) 
			return;

		else
		{
			cout << PNode->Data << " ";
			PreOrder(PNode->Left);
			PreOrder(PNode->Right);
		}
	}
	void InOrder(Node* PNode)// Left → Root → Right
	{
		if (PNode == NULL)
			return;
		else
		{
			InOrder(PNode->Left);
			cout << PNode->Data << " ";
			InOrder(PNode->Right);
		}
	}
	void PostOrder(Node* PNode)// Left → Right → Root
	{
		if (PNode == NULL)
			return;
		else
		{
			PostOrder(PNode->Left);
			PostOrder(PNode->Right);
			cout << PNode->Data << " ";
		}
	}

	Node* Search(Node* PNode, int NeededElement)
	{
		if (PNode == NULL)
		{
			return NULL;
		}
		else
		{
			if(NeededElement == PNode->Data)
			{
				return PNode;
			}
			else if(NeededElement <= PNode->Data)
			{
				Search(PNode->Left, NeededElement);
			}
			else if(NeededElement > PNode->Data)
			{
				Search(PNode->Right, NeededElement);
			}
			else
			{
				cout << "The element not found" << endl;
			}
		}
	}
	string Search(int NeededElement)
	{
		//return Root = Search(Root, NeededElement); correct 
		//return Result? true : false;
		//Node* Result = Search(Root, NeededElement);
		return Search(Root, NeededElement) ? "Element is found" : "Element is not found";
	}
	Node* FindMin(Node* PNode)
	{
		if(PNode == NULL)
			return NULL;
		else if(PNode->Left == NULL)
			return PNode;
		else
			FindMin(PNode->Left);
	}	
	Node* FindMax(Node* PNode)
	{
		if (PNode == NULL)
			return NULL;
		else if (PNode->Right == NULL)
			return PNode;
		else
			FindMax(PNode->Right);
	}

#pragma region Explain Delete Function
	//[1] NULL
	//[2] The node is left
	//[3] The node is right
	//[4] The node is root (parent)
		//[4.1]leaf node
		//[4.2]node parent has only one child(right ot left) → copy the child data to parent then delete the child 
		//[4.3]node parent has two children → must do one of the following two ways
			//4.3.1- replace the parent by the maximum node in the left (predecessor)
			//4.3.2- replace the parent by the minimun node in the right (successor)  
#pragma endregion
	Node* Delete(Node* PNode, int DeletedElement)
	{
		if (PNode == NULL)
			return NULL;
		else if (DeletedElement < PNode->Data)
			PNode->Left = Delete(PNode->Left, DeletedElement);
		else if (DeletedElement > PNode->Data)
			PNode->Right = Delete(PNode->Right, DeletedElement);
		else
		{
			if (PNode->Left == NULL && PNode->Right == NULL) // leaf node 
			{
				//PNode = NULL;
				delete PNode;
				return NULL;
			}
			else if (PNode->Right == NULL)
			{
				PNode->Data = PNode->Left->Data;
				PNode->Left = NULL;
				delete PNode->Left;
			}
			else if (PNode->Left == NULL)
			{
				PNode->Data = PNode->Right->Data;
				PNode->Right = NULL;
				delete PNode->Right;
			}
			else
			{
				Node* MaximumNodeInTheLeft = FindMax(PNode->Left);
				PNode->Data = MaximumNodeInTheLeft->Data;
				PNode->Left = Delete(PNode->Left, MaximumNodeInTheLeft->Data);
				/*or
				PNode->Data = FindMin(PNode->Right)->Data;*/
			}
		}
		return PNode;
	}
	Node* Delete(int DeletedElement)
	{
		return Delete(Root, DeletedElement);
	}
};

void Menu()
{
	cout << "[1] Add values" << endl;
	cout << "[2] Display Preorder" << endl;
	cout << "[3] Display Inorder" << endl;
	cout << "[4] Display Postorder" << endl;
	cout << "[5] Search" << endl;
	cout << "[6] Find Minimum" << endl;
	cout << "[7] Find Maximum" << endl;
	cout << "[8] Delete" << endl;
	//clear
}

int main()
{
	//45 15 79 90 10 55 12 20 50
	int CountNumbers, Value, NeedeElement, Choice, DeletedElement;
	BST BinaryTree;
	while (true)
	{
		Menu();
		cout << "Enter the choice" << endl;
		cin >> Choice;
		switch (Choice)
		{
		case 1:
		{
			cout << "How many numbers ? ";
			cin >> CountNumbers;
			cout << "Enter the values : ";
			for (int Index = 0; Index < CountNumbers; Index++)
			{
				cin >> Value;
				BinaryTree.Insert(Value);
			}
			break;
		}
		case 2:
		{
			cout << "The content : " << endl;
			cout << "In PreOrder Format : ";
			BinaryTree.PreOrder(BinaryTree.Root);
			cout << "\n---------------------------\n";
			break;
		}
		case 3:
		{
			cout << "In InOrder Format : ";
			BinaryTree.InOrder(BinaryTree.Root);
			cout << "\n---------------------------\n";
			break;
		}
		case 4:
		{
			cout << "In PostOrder Format : ";
			BinaryTree.PostOrder(BinaryTree.Root);
			cout << "\n---------------------------\n";
			break;
		}
		case 5:
		{
			cout << "Enter the element to search : ";
			cin >> NeedeElement;
			cout << BinaryTree.Search(NeedeElement) << endl;
			break;
		}
		case 6:
		{
			Node* Min = BinaryTree.FindMin(BinaryTree.Root);
			if (Min)
				cout << "The minimum number : " << Min->Data << endl;
			else
				cout << "No elements in the tree" << endl;
			break;
		}
		case 7:
		{
			Node* Max = BinaryTree.FindMax(BinaryTree.Root);
			if (Max)
				cout << "The minimum number : " << Max->Data << endl;
			else
				cout << "No elements in the tree" << endl;
			break;
		}
		case 8:
		{
			cout << "Enter the element that you want to delete it : ";
			cin >> DeletedElement;

			cout << "The tree before delete : ";
			BinaryTree.PreOrder(BinaryTree.Root);
			cout << endl;

			if (BinaryTree.Delete(DeletedElement) != NULL)
			{
				cout << "The tree after delete : ";
				BinaryTree.PreOrder(BinaryTree.Root);
				cout << endl;
			}
			else
				cout << "The tree is empty" << endl;
			break;
		}
		default:
			cout << "Invalid choice !" << endl;
		}
	}
}
