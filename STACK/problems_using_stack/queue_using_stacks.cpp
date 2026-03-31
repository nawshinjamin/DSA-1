#include<iostream>
#include<stack>

using namespace std;

class myqueue{
    stack<int> s1,s2;

    public:

    // enqueue operation (costly)
    void enqueue(int x){

        // move all elements from s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        // push the new item into s1
        s1.push(x);

        // push everything back to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    // dequeue operation
    void dequeue(){
        if(s1.empty()){
            // queue overflow
            return;
        }

        s1.pop();
    }

    // front operation
    int front(){
        if(s1.empty()){
        //queue empty
        return -1;
        }
        return s1.top();
    }

    // size operation
    int size(){
        return s1.size();
    }
};


int main() {
    myqueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front: " << q.front() << '\n';  
    cout << "Size: " << q.size() << '\n';    

    q.dequeue();              
    cout << "Front: " << q.front() << '\n';   
    cout << "Size: " << q.size() << '\n';    

    return 0;
}