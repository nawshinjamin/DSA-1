/*You have implemented List ADT in your offline. Now, you need to add a new
functionality to the ADT (both arrayList and linkedList) using the codes you have written
in the offline. Suppose the initial list is [ 1 2| 3 ]

Function (11) Parameters After Execution
surprise_insert(int item) 4 [ 1 2 4| 3 ]
6 [ 1 2 4| 3 6 ]
5 [ 1 2 4 5| 3 6 ]
This function alternates between insert function and append function [When first called
on a list, it does insert. One next call it appends. Then, on further call it inserts and so
on]. The number of the function is 11.

Sample Input Sample Output

11 1
11 2
11 3
11 4
11 5
11 6

[ 1| ]
[ 1| 2 ]
[ 1 3| 2 ]
[ 1 3| 2 4]
[ 1 3 5| 2 4 ]
[ 1 3 5| 2 4 6 ]

We are ignoring other log prints you have printed during your offline. You can keep them
as they are, or discard them.*/

#include <iostream>
using namespace std;

// ---------------- ArrayList Implementation ----------------
class ArrayList {
    int arr[100];   // fixed size for simplicity
    int length;
    bool toggle; // alternation flag
public:
    ArrayList() {
        length = 0;
        toggle = true; // প্রথমবার insert হবে
    }

    void insertAtEnd(int val) {
        arr[length++] = val;
    }

    void append(int val) {
        arr[length++] = val;
    }

    void surprise_insert(int val) {
        if(toggle) {
            // insert before last element (if exists)
            int pos = length; 
            if(length > 0) pos = length - 1;
            for(int i = length; i > pos; i--) {
                arr[i] = arr[i-1];
            }
            arr[pos] = val;
            length++;
        } else {
            append(val);
        }
        toggle = !toggle; // flip alternation
    }

    void print() {
        cout << "[ ";
        for(int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << "| ]" << endl;
    }
};

// ---------------- LinkedList Implementation ----------------
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
    Node* head;
    Node* tail;
    bool toggle;
public:
    LinkedList() {
        head = tail = NULL;
        toggle = true;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if(!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertBeforeTail(int val) {
        if(!head) {
            append(val);
            return;
        }
        if(head == tail) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        newNode->next = tail;
        temp->next = newNode;
    }

    void surprise_insert(int val) {
        if(toggle) insertBeforeTail(val);
        else append(val);
        toggle = !toggle;
    }

    void print() {
        cout << "[ ";
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "| ]" << endl;
    }
};

// ---------------- Main Function ----------------
int main() {
    cout << "ArrayList Demo:" << endl;
    ArrayList arrList;
    arrList.surprise_insert(1);
    arrList.print(); // [ 1| ]
    arrList.surprise_insert(2);
    arrList.print(); // [ 1| 2 ]
    arrList.surprise_insert(3);
    arrList.print(); // [ 1 3| 2 ]
    arrList.surprise_insert(4);
    arrList.print(); // [ 1 3| 2 4 ]
    arrList.surprise_insert(5);
    arrList.print(); // [ 1 3 5| 2 4 ]
    arrList.surprise_insert(6);
    arrList.print(); // [ 1 3 5| 2 4 6 ]

    cout << "\nLinkedList Demo:" << endl;
    LinkedList list;
    list.surprise_insert(1);
    list.print(); // [ 1| ]
    list.surprise_insert(2);
    list.print(); // [ 1| 2 ]
    list.surprise_insert(3);
    list.print(); // [ 1 3| 2 ]
    list.surprise_insert(4);
    list.print(); // [ 1 3| 2 4 ]
    list.surprise_insert(5);
    list.print(); // [ 1 3 5| 2 4 ]
    list.surprise_insert(6);
    list.print(); // [ 1 3 5| 2 4 6 ]

    return 0;
}