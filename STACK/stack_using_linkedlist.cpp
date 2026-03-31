#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class stack
{
    Node *top;

public:
    stack()
    {
        top = nullptr;
    }

    void push(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        cout << val << " pushed to stack" << endl;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "stack overflow" << endl;
            return;
        }
        cout << top->data << " popped from stack" << endl;
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    void peek()
    {
        if (top == nullptr)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << "top element is : " << top->data << endl;
        }
    }
    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
};

int main()
{
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.peek();
    s.pop();
    s.display();

    return 0;
}
