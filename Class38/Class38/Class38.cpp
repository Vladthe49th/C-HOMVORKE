#include <iostream>
#include <utility>
#include <string>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main()
{
	/*set<int> s = { 11, 3, 1, 4, 1, 5, 9, 14, 2, 21 };

	for (int number : s)
	{
		cout << setw(5) << number;
	}
	auto iter = s.lower_bound(3);
	cout << endl << *iter << endl;

	cout << *s.upper_bound(37) << endl;

	if (s.insert(72).second)
	{
		cout << "Successfully Added" << endl;
	}

	for (int number : s)*/

#pragma region Adapters
	stack<int> myStack;
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);

	while (!myStack.empty())
	{
		cout << myStack.top() << endl;
		myStack.pop();
	}

	stack<int> myStack2
}