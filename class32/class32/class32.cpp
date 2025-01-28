#include <iostream>
#include <exception>
using namespace std;

int Foo(int a, int b)
{
	if (b == 0)
	{
		throw "Divide by zero";
	}
	return a / b;
}

int main()
{
	Foo(16, 1);
}