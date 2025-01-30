#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream file;
	file.open("test.txt");
	if (!file.is_open())
	{
		throw exception("Couldn`t open the file");
	}
	string line;
	while (!file.eof())
	{
		getline(file, line);
		cout << line << endl;
	}
	file.close();

}