#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    T data;
    Node* next;
public:
    Node(T data) : data(data), next(nullptr) {}

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
};

template <typename T>
class Stack
{
private:
    Node<T>* top;
    size_t size;
public:
    Stack() : top(nullptr), size(0) {}

    size_t GetSize() const
    {
        return size;
    }

    void Push(T data) // adding elems to the top
    {
        Node<T>* newNode = new Node<T>(data);
        newNode->SetNext(top);
        top = newNode;
        size++;
    }

    T& Peek() // get the top elem
    {
        if (top == nullptr)
        {
            throw runtime_error("Stack is empty");
        }
        return top->GetData();
    }

    void Pop() // pop the top weasel
    {
        if (top == nullptr)
        {
            throw runtime_error("Stack is empty");
        }
        Node<T>* temp = top;
        top = top->GetNext();
        delete temp;
        size--;
    }

    ~Stack()
    {
        while (top != nullptr)
        {
            Node<T>* temp = top;
            top = top->GetNext();
            delete temp;
        }
    }
};

int main()
{
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(6);
    stack.Push(9);
    stack.Push(123);
    while (stack.GetSize() != 0)
    {
        cout << stack.Peek() << endl;
        stack.Pop();
    }

    cout << "Now using with strings:" << endl;

    Stack<string> stringStack;
    stringStack.Push("Hello");
    stringStack.Push("My dear");
    stringStack.Push("Palmolive - the nejnyi gel");
    while (stringStack.GetSize() != 0)
    {
        cout << stringStack.Peek() << endl;
        stringStack.Pop();
    }
}