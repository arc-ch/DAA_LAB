#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted with node i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to build a heap
void buildHeap(vector<int>& arr) {
    int n = arr.size();

    // Index of last non-leaf node
    int startIdx = n / 2 - 1;

    // Perform reverse level order traversal
    // from the last non-leaf node and heapify
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
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

    buildHeap(arr);

    cout << "Heap array: ";
    printHeap(arr);

    return 0;
}

