#include <iostream>
#include <stack>
using namespace std;

bool ArePair(char Open, char Close)
{
	return (Open == '(' && Close == ')') ||
		   (Open == '{' && Close == '}') ||
		   (Open == '[' && Close == ']');
}

bool AreBalanced(string Expression)
{
	stack<char> Stack;
	for (int Index = 0; Index < Expression.length(); Index++)
	{
		if (Expression[Index] == '(' || Expression[Index] == '{' || Expression[Index] == '[')
		{
			Stack.push(Expression[Index]);
		}
		else if (Expression[Index] == ')' || Expression[Index] == '}' || Expression[Index] == ']')
		{
			if (Stack.empty() || !ArePair(Stack.top(), Expression[Index]))
			{
				return false;
			}
			else 
			{
				Stack.pop();
			}
		}
	}
	return Stack.empty()? true:false;
}

int main()
{
	string Expression;
	while (1)
	{
		cout << "Enter The Expression : ";
		cin >> Expression;
		if (AreBalanced(Expression))
		{
			cout << "Balanced" << endl;
		}
		else
		{
			cout << "Not Balanced" << endl;
		}
	}
}
