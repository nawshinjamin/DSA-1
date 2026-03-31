#include <iostream>
using namespace std;

#define MAX 3
class stack
{
private:
    int arr[MAX];
    int top;

public:
    stack()
    {
        top = -1;
    }
    void push(int val)
    {
        if (top == MAX - 1)
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            arr[++top] = val;
            cout << val << " pushed to stack" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            cout << arr[top--] << " popped from stack " << endl;
        }
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            cout << arr[top] << " is at the top of the stack" << endl;
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << "stack elements: ";
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX-1;
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