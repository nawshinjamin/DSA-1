#include<iostream>
#include<stack>

using namespace std;

template<typename T>

class MyQueue{
    private:
    stack<T> s1;
    stack<T> s2;

    public:

    void enqueue(T item){
        s1.push(item);
    }

    T dequeue(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()){
            throw runtime_error("Queue is empty");
            
        }
        T val = s2.top;
        s2.pop;
        return val;
    }
           T peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            throw runtime_error("Queue is empty!");
        }
        return s2.top();
    }

    // Check if queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    

};

int main(){

 MyQueue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeued: " << q.dequeue() << endl; // 10
    cout << "Peek: " << q.peek() << endl;        // 20
    cout << "Dequeued: " << q.dequeue() << endl; // 20
    cout << "Dequeued: " << q.dequeue() << endl; // 30

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;









    return 0;
}