#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <climits>

#define MAX_CAPACITY 1000  // Defines the maximum capacity of the heap

class MinHeap
{
private:
    int heap[MAX_CAPACITY];  // Array to store heap elements
    int size;                // Current number of elements in the heap

    /**
     * Sifts up the node at index i to maintain heap property.
     */
    void siftUp(int i)
    {
        /**Write your code here**/
        while(i > 0 && heap[(i-1)/2] > heap[i]){
            std ::  swap(heap[i] , heap[(i-1) / 2]);
            i = (i - 1) / 2;
        }
    }

    /**
     * Sifts down the node at index i to maintain heap property.
     */
    void siftDown(int i)
    {
        /**Write your code here**/
        int s= i;
    int l= 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l] < heap[s])
        s = l;

    if (r < size && heap[r] < heap[s])
        s = r;

    if (s != i)
    {
        std::swap(heap[i], heap[s]);
        siftDown(s);
    }
      }

public:
    // Constructor initializes an empty heap
    MinHeap() : size(0) {}

    /**
     * Inserts a new element x into the heap.
     */
    void insert(int x)
    {
        /**Write your code here**/
        if(size == MAX_CAPACITY)
        throw std :: overflow_error("Heap overflow");
        heap[size] = x;
        siftUp(size);
    size++;    }

    /**
     * Returns the minimum element without removing it.
     */
    int findMin()
    {
        /**Write your code here**/
        if(size == 0)
        throw std :: underflow_error("Heap is empty");
        return heap[0];
    }

    /**
     * Removes and returns the minimum element from the heap.
     */
    int extractMin()
    {

        /**Write your code here**/
        if(size == 0)
        throw std :: underflow_error("Heap is empty");
        int r = heap[0];
        heap[0] = heap[size - 1];
        size--;
        siftDown(0);
        return r;

    }

    /**
     * Returns the number of elements in the heap.
     */
    int getSize()
    {
        /**Write your code here**/
        return size;
    }

    /**
     * Checks if the heap is empty.
     * Returns true if empty, false otherwise.
     */
    bool isEmpty()
    {
        /**Write your code here**/
        return (size == 0);
    }

    /**
     * Decreases the value of the element at index i to newValue.
     */
    void decreaseKey(int i, int newValue)
    {
        /**Write your code here**/
        if(i < 0 || i >= size)
        throw std :: out_of_range("Index out of range");
        if (newValue > heap[i])
        throw std::invalid_argument("New value is greater than current value");

        heap[i] = newValue;
        siftUp(i);

    }

    /**
     * Deletes the element at index i.
     */
    void deleteKey(int i)
    {
        /**Write your code here**/
        decreaseKey(i , INT_MIN);
        extractMin();
    }

    /**
     * Prints the heap's content to the output file.
     * Format: "elem1 elem2 elem3 ..." (space-separated)
     */
    void printHeap(std::ofstream &outfile)
    {
        /**Write your code here**/
        
        for (int i = 0; i < size; i++)
        {
            outfile << heap[i] << " ";
        }
        outfile << std::endl;

    }

    /**
     * Checks whether the Min Heap property is preserved.
     * Returns true if valid, false otherwise.
     */
    bool isValidMinHeap()
    {
        /**Write your code here**/
         for (int i = 0; i <= (size - 2) / 2; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < size && heap[i] > heap[left]) return false;
            if (right < size && heap[i] > heap[right]) return false;
        }
        return true;

    }

    /**
     * Builds a heap from an unsorted array using bottom-up heapify.
     */
    void heapify(int arr[], int n)
    {
        /**Write your code here**/
         if (n > MAX_CAPACITY)
            throw std::overflow_error("Array too large");
         for (int i = 0; i < n; i++)
        heap[i] = arr[i];

    size = n;

    for (int i = size/2 - 1; i >= 0; i--)
    {
        siftDown(i);
    }
    }

    /**
     * Returns all elements in sorted (ascending) order.
     * The original heap should remain UNCHANGED after this operation.
     */
    void heapSort(std::ofstream &outfile)
    {
        /**Write your code here**/
         MinHeap temp;
        for(int i=0; i<size; i++)
            temp.insert(heap[i]);

        
        while (!temp.isEmpty())
        {
            outfile << temp.extractMin() << " ";
        }
        outfile << std::endl;

    }

    /**
     * Replaces the minimum element with a new value x in a single operation.
     * Returns the old minimum value.
     */
    int replaceMin(int x)
    {
        /**Write your code here**/
         if (size == 0)
            throw std::underflow_error("Heap is empty");
        int root = heap[0];
        heap[0] = x;
        siftDown(0);
        return root;

    }
};

#endif // MINHEAP_H
