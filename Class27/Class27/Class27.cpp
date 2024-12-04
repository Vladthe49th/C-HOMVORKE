#include <iostream>
using namespace std;

class MyInt
{
private:
	int value;
public:
	MyInt(int value)
	{
		this->value = value;
	}
	void SetData(int value)
	{
		this->value = value;
	}
	int GetData() const
	{
		return value;
	}
};

class Node
{
private:
	MyInt myInt;
	Node* next /*= nullptr*/;
public:
	Node(MyInt myInt) : myInt(myInt), next(nullptr) {}
	MyInt GetMyInt() const
	{
		return myInt;
	}
	void SetMyInt(MyInt myInt)
	{
		this->myInt = myInt;
	}
	Node* GetNext() const
	{
		return next;
	}
	void SetNext(Node* next)
	{
		this->next = next;
	}
};

class LinkedList
{
private:
	Node* head;
	size_t size;
public:
	LinkedList() : head(nullptr), size(0) {}
	size_t GetSize() const
	{
		return size;
	}
	void InsertAtEnd(MyInt value)
	{
		if (head == nullptr)
		{
			InsertAtBeginning(value);
			return;
		}
		Node* newNode = new Node(value);

		Node* temp = head;
		while (temp->GetNext() != nullptr)
		{
			temp = temp->GetNext();
		}
		temp->SetNext(newNode);
		size++;
	}
	void InsertAtBeginning(MyInt value)
	{
		Node* newNode = new Node(value);
		newNode->SetNext(head);
		head = newNode;
		size++;
	}

	void DeleteFromBeginning()
	{
		if (head == nullptr)
		{
			cout << "List is empty!" << endl;
			return;
		}
		Node* temp = head;
		head = head->GetNext();
		delete temp;
		size--;
	}

	void DeleteFromEnd()
	{
		if (head == nullptr)
		{
			cout << "List is empty!" << endl;
			return;
		}
		if (head->GetNext() == nullptr)
		{
			delete head;
			head = nullptr;
			size--;
			return;
		}
		Node* temp = head;
		while (temp->GetNext()->GetNext() != nullptr)
		{
			temp = temp->GetNext();
		}
		delete temp->GetNext();
		temp->SetNext(nullptr);
		size--;
	}

	MyInt GetIndex(size_t index) const
	{
		if (index >= size)
		{
			throw out_of_range("Wrong index, Carl!");
		}
		Node* temp = head;
		for (size_t i = 0; i < index; i++)
		{
			temp = temp->GetNext();
		}
		return temp->GetMyInt();
	}

	void PrintList() const
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->GetMyInt().GetData() << " ";
			temp = temp->GetNext();
		}
		cout << endl;
	}


	~LinkedList()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->GetNext();
			delete temp;
		}
	}

	class Iterator
	{
	private:
		Node* current;
	public:
		Iterator(Node* start) : current(start) {}

		bool HasNext() const
		{
			return current != nullptr;
		}

		MyInt Next()
		{
			if (!HasNext())
			{
				throw out_of_range("No more elements in the list");
			}
			MyInt value = current->GetMyInt();
			current = current->GetNext();
			return value;
		}
	};

	Iterator GetIterator() const
	{
		return Iterator(head);
	}
};


int main()
{
	LinkedList* list = new LinkedList();
	list->InsertAtBeginning(MyInt(5));
	list->InsertAtEnd(MyInt(7));
	list->InsertAtEnd(MyInt(9));

	cout << "List after adding elements: ";
	list->PrintList();

	list->DeleteFromBeginning();
	cout << "List after deleting from beginning: ";
	list->PrintList();

	list->DeleteFromEnd();
	cout << "List after deleting from end: ";
	list->PrintList();

	try
	{
		cout << "Element at 0: " << list->GetIndex(0).GetData() << endl;
	}
	catch (const out_of_range& e)
	{
		cout << e.what() << endl;
	}

	cout << "Iteration go go go: ";
	LinkedList::Iterator it = list->GetIterator();
	while (it.HasNext())
	{
		cout << it.Next().GetData() << " ";
	}
	cout << endl;

	delete list;

	// індексація
	// вивід елементів через цикл 
}