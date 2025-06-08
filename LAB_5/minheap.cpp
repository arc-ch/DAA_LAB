#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted with node i (for Min Heap)
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than the smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        minHeapify(arr, n, smallest);
    }
}

// Function to build a min heap
void buildMinHeap(vector<int>& arr) {
    int n = arr.size();

    // Index of last non-leaf node
    int startIdx = n / 2 - 1;

    // Perform reverse level order traversal
    // from the last non-leaf node and heapify
    for (int i = startIdx; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Function to print the array representation of the heap
void printHeap(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    buildMinHeap(arr);

    cout << "Min Heap array: ";
    printHeap(arr);

    return 0;
}

