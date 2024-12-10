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
    Node* prev;
public:
    Node(T data) : data(data), next(nullptr), prev(nullptr) {}

    T& GetData()
    {
        return data;
    }

    void SetData(T data)
    {
        this->data = data;
    }

    Node* GetNext() const
    {
        return next;
    }

    void SetNext(Node* next)
    {
        this->next = next;
    }

    Node* GetPrev() const
    {
        return prev;
    }

    void SetPrev(Node* prev)
    {
        this->prev = prev;
    }
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

    size_t Size() const
    {
        return size;
    }

    void EnqueueBack(T data)
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
            newNode->SetPrev(last);
            last = newNode;
        }
        size++;
    }

    void EnqueueFront(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        if (first == nullptr)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            newNode->SetNext(first);
            first->SetPrev(newNode);
            first = newNode;
        }
        size++;
    }

    T& Front()
    {
        if (first == nullptr)
        {
            throw runtime_error("Queue is empty!");
        }
        return first->GetData();
    }

    const T Front() const
    {
        if (first == nullptr)
        {
            throw runtime_error("Queue is empty!");
        }
        return first->GetData();
    }

    T& Back()
    {
        if (last == nullptr)
        {
            throw runtime_error("Queue is empty!");
        }
        return last->GetData();
    }

    const T Back() const
    {
        if (last == nullptr)
        {
            throw runtime_error("Queue is empty!");
        }
        return last->GetData();
    }

    void DequeueFront()
    {
        if (first == nullptr)
        {
            return;
        }
        Node<T>* temp = first;
        first = first->GetNext();
        if (first != nullptr)
        {
            first->SetPrev(nullptr);
        }
        if (first == nullptr)
        {
            last = nullptr;
        }
        delete temp;
        size--;
    }

    void DequeueBack()
    {
        if (last == nullptr)
        {
            return;
        }
        Node<T>* temp = last;
        last = last->GetPrev();
        if (last != nullptr)
        {
            last->SetNext(nullptr);
        }
        if (last == nullptr)
        {
            first = nullptr;
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
    Queue<int> queue; //Int queue
    queue.EnqueueBack(9);
    queue.EnqueueBack(1);
    queue.EnqueueBack(5);
    queue.EnqueueBack(7);
    queue.EnqueueBack(3);

    for (int i = queue.Size(); i > 0; i--)
    {
        cout << queue.Front() << endl;
        queue.DequeueFront();
    }

    Queue<string> stringQueue; // String queue
    stringQueue.EnqueueBack("I");
    stringQueue.EnqueueBack("Love");
    stringQueue.EnqueueBack("Windows");

    while (stringQueue.Size() > 0)
    {
        cout << stringQueue.Front() << endl;
        stringQueue.DequeueFront();
    }


}