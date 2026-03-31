/*You have implemented List ADT in your offline. Now, you need to add a new
functionality to the ADT (both arrayList and linkedList) using the codes you have written
in the offline. Suppose the initial list is [ 3 4 5 6 7| 8 ]
Function (11) Parameters After Execution
reverse_pos(int ind1, int ind2) 2, 5 [ 3 4 8 7 6| 5 ]
This function reverses the order of the items between two indices (assume only valid
indices will be input). The number of the function is 11.

Sample Input Sample Output

1 1
1 2
1 3
1 4
1 5
1 6
1 7
11 1 3
11 0 4
11 0 6

[ 1| ]
[ 1 2| ]
[ 1 2 3| ]
[ 1 2 3 4| ]
[ 1 2 3 4 5| ]
[ 1 2 3 4 5 6| ]
[ 1 2 3 4 5 6 7| ]
[ 1 4 3 2 5 6 7| ]
[ 5 2 3 4 1 6 7| ]
[ 7 6 1 4 3 2 5| ]

We are ignoring other log prints you have printed during your offline. You can keep them
as they are, or discard them.*/

#include <iostream>
using namespace std;

// ---------------- ArrayList Implementation ----------------
class ArrayList {
    int arr[100];   // fixed size for simplicity
    int length;
public:
    ArrayList() { length = 0; }

    void insert(int val) {
        arr[length++] = val;
    }

    void reverse_pos(int ind1, int ind2) {
        while(ind1 < ind2) {
            int temp = arr[ind1];
            arr[ind1] = arr[ind2];
            arr[ind2] = temp;
            ind1++;
            ind2--;
        }
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
    int length;
public:
    LinkedList() { head = NULL; length = 0; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if(!head) head = newNode;
        else {
            Node* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = newNode;
        }
        length++;
    }

    void reverse_pos(int ind1, int ind2) {
        // find start and end nodes
        Node* start = head;
        for(int i = 0; i < ind1; i++) start = start->next;

        Node* end = head;
        for(int i = 0; i < ind2; i++) end = end->next;

        // swap values between start and end moving inward
        while(ind1 < ind2) {
            int temp = start->data;
            start->data = end->data;
            end->data = temp;

            start = start->next;
            ind1++;

            // move end backwards (inefficient but works)
            Node* tempNode = head;
            for(int i = 0; i < ind2-1; i++) tempNode = tempNode->next;
            end = tempNode;
            ind2--;
        }
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
    arrList.insert(1);
    arrList.insert(2);
    arrList.insert(3);
    arrList.insert(4);
    arrList.insert(5);
    arrList.insert(6);
    arrList.insert(7);

    arrList.print(); // [ 1 2 3 4 5 6 7 | ]
    arrList.reverse_pos(1, 3);
    arrList.print(); // [ 1 4 3 2 5 6 7 | ]
    arrList.reverse_pos(0, 4);
    arrList.print(); // [ 5 2 3 4 1 6 7 | ]
    arrList.reverse_pos(0, 6);
    arrList.print(); // [ 7 6 1 4 3 2 5 | ]

    cout << "\nLinkedList Demo:" << endl;
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);

    list.print(); // [ 1 2 3 4 5 6 7 | ]
    list.reverse_pos(1, 3);
    list.print(); // [ 1 4 3 2 5 6 7 | ]
    list.reverse_pos(0, 4);
    list.print(); // [ 5 2 3 4 1 6 7 | ]
    list.reverse_pos(0, 6);
    list.print(); // [ 7 6 1 4 3 2 5 | ]

    return 0;
}