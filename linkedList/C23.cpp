/*You have implemented List ADT in your offline. Now, you need to add a new
functionality to the ADT (both arrayList and linkedList) using the codes you have written
in the offline. Suppose the initial list is [ 3 4 5| 6 7 8 ]
Function (11) Parameters After Execution
combine() - [ 3 4 18| 8 ]
- Invalid
This function combines three (current and next two) nodes. If there are less than two
elements after the current one, print ‘Invalid’. The number of the function is 11.

Sample Input Sample Output

1 1
1 2
1 3
1 4
1 5
1 6
1 7
5 6
11
6 1
11
11

[ 1| ]
[ 1 2| ]
[ 1 2 3| ]
[ 1 2 3 4| ]
[ 1 2 3 4 5| ]
[ 1 2 3 4 5 6| ]
[ 1 2 3 4 5 6 7| ]
[ 1| 2 3 4 5 6 7 ]
[ 6| 4 5 6 7 ]
[ 6 4| 5 6 7 ]
[ 6 15| 7 ]
Invalid

We are ignoring other log prints you have printed during your offline. You can keep them
as they are, or discard them.*/

#include <iostream>
using namespace std;

// ---------------- ArrayList Implementation ----------------
class ArrayList {
    int arr[100];
    int length;
    int currPos; // cursor position
public:
    ArrayList() {
        length = 0;
        currPos = -1; // initially no cursor
    }

    void insert(int val) {
        arr[length++] = val;
        if(currPos == -1) currPos = 0; // প্রথমবার cursor শুরুতে থাকবে
    }

    void moveToPos(int pos) {
        if(pos >= 0 && pos < length) currPos = pos;
    }

    void combine() {
        if(currPos == -1 || currPos+2 >= length) {
            cout << "Invalid" << endl;
            return;
        }
        int sum = arr[currPos] + arr[currPos+1] + arr[currPos+2];
        arr[currPos] = sum;
        // shift left
        for(int i = currPos+1; i+2 < length; i++) {
            arr[i] = arr[i+2];
        }
        length -= 2;
    }

    void print() {
        cout << "[ ";
        for(int i = 0; i < length; i++) {
            if(i == currPos) cout << arr[i] << "| ";
            else cout << arr[i] << " ";
        }
        cout << "]" << endl;
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
    Node* curr; // cursor
public:
    LinkedList() {
        head = NULL;
        curr = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if(!head) {
            head = newNode;
            curr = head;
        } else {
            Node* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void moveToPos(int pos) {
        Node* temp = head;
        for(int i = 0; i < pos && temp; i++) temp = temp->next;
        curr = temp;
    }

    void combine() {
        if(!curr || !curr->next || !curr->next->next) {
            cout << "Invalid" << endl;
            return;
        }
        int sum = curr->data + curr->next->data + curr->next->next->data;
        curr->data = sum;
        Node* temp = curr->next->next->next;
        delete curr->next;
        delete curr->next->next;
        curr->next = temp;
    }

    void print() {
        cout << "[ ";
        Node* temp = head;
        while(temp) {
            if(temp == curr) cout << temp->data << "| ";
            else cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "]" << endl;
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

    arrList.print(); // [ 1 2 3 4 5 6 7| ]
    arrList.moveToPos(1);
    arrList.combine();
    arrList.print(); // combine at pos 1

    arrList.moveToPos(4);
    arrList.combine(); // Invalid

    cout << "\nLinkedList Demo:" << endl;
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);

    list.print(); // [ 1 2 3 4 5 6 7| ]
    list.moveToPos(1);
    list.combine();
    list.print();

    list.moveToPos(4);
    list.combine(); // Invalid

    return 0;
}