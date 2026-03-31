#include <iostream>
#include <stack>

using namespace std;

int main()
{

    stack<int> s;

    s.push(10);
    s.push(20);

    // Accessing top element
    cout << "Top element before pop: " << s.top() << endl;

    // size of stack
    cout << "size of stack: " << s.size() << endl; 

    // create a copy
    stack<int> temp(s);
cout << "after copying : ";

    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    // Popping an element
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;
      cout << "size of stack after pop : " << s.size() << endl; 
    return 0;
}