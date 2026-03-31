#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
    

};

class queue{
Node* head;
Node* tail;

public:
queue(){
    head = tail = nullptr; 
}

void push(int val){ // insert data at the tail
     Node* newNode = new Node(val);

     if(empty()){
        head = tail = newNode;

     }
     else{
        tail->next = newNode ;
        tail = newNode;
     }
}

void pop()
{
if(empty()){
    cout << "LL is empty\n";
    return;
}

    Node* temp = head;
    head = head->next;
    delete temp;

}

int front(){
    if(empty()){
        cout << "LL is empty\n" ;
        return -1;
    }
    return head->data;
}
bool empty(){
    return head == NULL;
}
};


int main(){
    queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
    return 0;
}