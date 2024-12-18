#include <iostream>
using namespace std;

class USB
{
public:
	virtual void Do()
	{
		cout << "connect\n";
	}
};

class Phone : public USB
{
public:
	virtual void Do() override
	{
		cout << "Charging\n";
	}
	void Call(string name)
	{
		cout << "Call to " << name << endl;
	}
};

int main()
{
	USB* phone = new Phone();
	phone->Do();

	cout << sizeof(*phone) << endl;
}