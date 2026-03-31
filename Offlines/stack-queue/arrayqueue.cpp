#include "queue.h"
#include <iostream>
using namespace std;


// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    // TODO: Allocate memory for the array with the specified initial capacity
    capacity = initial_capacity;
    if(capacity<2)
    capacity = 2;
    data = new int[capacity];
front_idx = -1;
rear_idx = -1;

    
}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    // TODO: Free the dynamically allocated memory for the array
    delete[] data;
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    // TODO: Check if the array is full
    // TODO: If full, resize the array to double its current capacity
    // TODO: Add the new element to the rear of the queue
    if(size() == capacity){
        resize(capacity * 2);
    }
    if(front_idx == -1){
        front_idx = 0;
        rear_idx = 0;
    }
    else{
        rear_idx = (rear_idx + 1) % capacity;
    }
data[rear_idx] = item;
}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Update front index
    // TODO: If the array is less than 25% full, resize it to half its current capacity (but not less than 2)
    // TODO: Return the dequeued element
    if(front_idx == -1){
        cout << "Error:The queue is empty" << endl;;
        return -1;
    }
    int x = data[front_idx];

    if(front_idx == rear_idx){
        front_idx = -1;
        rear_idx = -1;
    }
    else{
        front_idx = (front_idx + 1) % capacity;
    }
    if(size() <= capacity / 4 && capacity > 2){
        resize(capacity / 2);
    }
    return x;
}

// Clear implementation
void ArrayQueue::clear()
{
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
    delete[] data;
    capacity = 2;
    data = new int[2];
    front_idx = -1;
    rear_idx = -1;
}

// Size implementation
int ArrayQueue::size() const
{
    // TODO: Return the number of elements currently in the queue
    int size;
    if(front_idx == -1){
        size = 0;
    }
    else if(front_idx <= rear_idx ){
        size = rear_idx - front_idx + 1;
    }
    else if(front_idx > rear_idx ){
        size = (capacity - front_idx) + (rear_idx + 1);
    }
return size;
}

// Front implementation
int ArrayQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the front of the queue without removing it
    if(front_idx == -1){
        cout << "Error: The queue is empty!" << endl;
        return -1;
    }
    else{
        return data[front_idx];
    }
}

// Back implementation (get the element at the back of the queue)
int ArrayQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the back of the queue without removing i
     if(front_idx == -1){
        cout << "Error: The queue is empty!"  << endl;;
        return -1;
    }
    else{
        return data[rear_idx];
    }
}

// Empty implementation
bool ArrayQueue::empty() const
{
   
    // TODO: Return whether the queue is empty
    return (front_idx == -1);
}

// Print implementation
string ArrayQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    string str = "<";
    int s = size();

    for(int i=0; i<s; i++){
      str += to_string(data[front_idx + i] % capacity);
      if(i != s-1)
      str += ",";
    }
    str += "|";
    return str;


}

// Resize implementation
void ArrayQueue::resize(int new_capacity)
{
    // TODO: Create a new array with the new capacity
    // TODO: Copy elements from the old array to the new array
    // TODO: Delete the old array
    // TODO: Update the data pointer and capacity
    // TODO: Update front and rear indices
   int* arr = new int[new_capacity];
   int s = size();
   for(int i=0; i<s; i++){
    arr[i] = data[(front_idx + i) % capacity] ;
   }
   delete[] data;
   data = arr;
   capacity = new_capacity;
   front_idx = 0;
   rear_idx = s - 1;
}

int ArrayQueue::getCapacity() const
{
    // TODO: Return the current capacity of the queue
    return capacity;
}
