#include <iostream>
using namespace std;

class MyInt
{
private:
	int value;
public:
	MyInt(int value = 0) : value(value) {}

	void SetData(int value) { this->value = value; }
	int GetData() const { return value; }
};

template <typename T>
class Node
{
private:
	T data;
	Node* next;
public:
	Node(T data) : data(data), next(nullptr) {}

	T& GetData() { return data; }
	void SetData(T data) { this->data = data; }

	Node* GetNext() const { return next; }
	void SetNext(Node* next) { this->next = next; }
};

template <typename T>
class Queue
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t size;
public:
    Queue() : first(nullptr), last(nullptr), size(0) {}

    size_t Size() const { return size; }

    void Enqueue(T data) // додавання елементів у кінець черги
    {
        Node<T>* newNode = new Node<T>(data);
        if (last == nullptr)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->SetNext(newNode);
            last = newNode;
        }
        size++;
    }

    T& Front() // отримання першого елемента
    {
        if (first == nullptr)
        {
            throw runtime_error("Queue is empty!");
        }
        return first->GetData();
    }

    const T Front() const // для константного об'єкта
    {
        if (first == nullptr)
        {
            throw runtime_error("Queue is empty!");
        }
        return first->GetData();
    }

    void Dequeue() // видалення першого елемента з черги
    {
        if (first == nullptr)
        {
            return;
        }
        Node<T>* temp = first;
        first = first->GetNext();
        if (first == nullptr)
        {
            last = nullptr;
        }
        delete temp;
        size--;
    }

    ~Queue()
    {
        while (first != nullptr)
        {
            Node<T>* temp = first;
            first = first->GetNext();
            delete temp;
        }
    }
};
int main()
{
    Queue<MyInt> queue;
    queue.Enqueue(MyInt(9));
    queue.Enqueue(MyInt(1));
    queue.Enqueue(MyInt(5));
    queue.Enqueue(MyInt(7));
    queue.Enqueue(MyInt(3));

    for (int i = queue.Size(); i > 0; i--)
    {
        cout << queue.Front().GetData() << endl;
        queue.Dequeue();
    }

    // Черга для int
    Queue<int> intQueue;
    intQueue.Enqueue(10);
    intQueue.Enqueue(20);
    intQueue.Enqueue(30);

    while (intQueue.Size() > 0)
    {
        cout << intQueue.Front() << endl;
        intQueue.Dequeue();
    }
}