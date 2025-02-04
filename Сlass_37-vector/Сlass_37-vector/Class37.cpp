#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
#pragma region Vector


	//vector<int> vec; // під капотом динамічний масив 
	//
	//vec.push_back(12); // додавання в кінец
	//vec.push_back(1);
	//vec.push_back(2);
	//vec.push_back(3);

	/*auto iter_vec = vec.begin();*/
	/*vector<int>::iterator iter_vec = vec.begin();*/

	//for(vector<int>::iterator iter_vec = vec.begin(); iter_vec != vec.end(); iter_vec++)
	//{
	//	cout << *iter_vec << endl;
	//}

	//for (size_t i = 0; i < vec.size(); i++)
	//{
	//	cout << vec[i] << endl;
	//}

	//for (auto iter : vec)
	//{
	//	cout << iter << endl;
	//}
	//cout << endl;
	//vec.pop_back(); // видалення останього елементу 
	//for (vector<int>::iterator iter_vec = vec.begin(); iter_vec != vec.end(); iter_vec++)
	//{
	//	cout << *iter_vec << endl;
	//}



	//vector<int> myVector = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

	/*vector<int> myVector2(123);
	cout << myVector2.size() << endl;
	cout << myVector2.capacity() << endl;*/

	/*myVector.insert(myVector.begin() + 3, 14);
	for (auto iter : myVector)
	{
		cout << iter << endl;
	}*/

	/*myVector.erase(myVector.end() - 1);
	for (auto iter : myVector)
	{
		cout << iter << endl;
	}*/
	/*myVector.erase(myVector.begin() + 2, myVector.begin() + 5);

	for (auto iter : myVector)
	{
		cout << iter << endl;
	}*/
	/*myVector.clear();
	if (myVector.empty())
	{
		cout << "There are no elements in your vector:(" << endl;
	}*/

	//for (vector<int>::iterator iter_vec = myVector.end() - 1; iter_vec != myVector.begin(); iter_vec--)
	//{
	//	cout << *iter_vec << endl;
	//}

	//for (auto iter_vec = myVector.rbegin(); iter_vec != myVector.rend(); iter_vec++)
	//{
	//	cout << *iter_vec << endl;
	//}
	//reverse_iterator<vector<int>::iterator>

	//int value = 7;

	//auto it = find(myVector.begin(), myVector.end(), value);
	//if (it != myVector.end())
	//{
	//	cout << distance(myVector.begin(), it) << endl;
	//}
	//int val = 3;
	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//auto position = find(arr, arr + 10, val);
	//cout << *position << endl;
#pragma endregion

#pragma region List


	//list<int> myList = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//for (auto iter = myList.begin(); iter != myList.end(); iter++)
	//{
	//	cout << *iter << endl;
	//}
	////for (auto iter : myList)
	////{
	////	cout << iter << endl;
	////}
	//myList.push_back(23);
	//myList.push_front(14);

	//myList.pop_back();
	//myList.pop_front();
	//for (size_t i = 0; i < myList.size(); i++)
	//{
	//	cout << myList[i] << endl;
	//}
#pragma endregion


#pragma region ForwardList

	forward_list<int> myList = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto iter = myList.begin(); iter != myList.end(); iter++)
	{
		cout << *iter << endl;
	}
	//for (auto iter : myList)
	//{
	//	cout << iter << endl;
	//}

	myList.push_front(14);

	myList.pop_front();

#pragma endregion


	//vector<int> arr(20);
	//for (size_t i = 0; i < arr.size(); i++)
	//{
	//	arr[i] = rand() % 1000;
	//	cout << setw(5) << arr[i];
	//}
	//sort(arr.begin(), arr.end());
	//cout << endl;
	//for (size_t i = 0; i < arr.size(); i++)
	//{
	//	cout << setw(5) << arr[i];
	//}


}