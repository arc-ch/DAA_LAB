#include <iostream>
#include "cmm.H"

using std::cout, std::endl;
_ count = 0;

// Merge FUNC
_ merge = [](_& A, _ p, _ q, _ r) {
    _ n1 = q - p + 1;
    _ n2 = r - q;

    _ L = get(range(n1), 0); // Temporary array for left half
    _ R = get(range(n2), 0); // Temporary array for right half

    // Copy data to temp arrays L[] and R[]
    for (_ i = 0; i < n1; ++i) {
        L[i] = A[p + i];
    }
    for (_ j = 0; j < n2; ++j) {
        R[j] = A[q + 1 + j];
    }

    _ i = 0; // idx of first subarray
    _ j = 0; //idx of second subarray
    _ k = p; //idx of merged subarray

    // Merge temp arrays back into A[p..r]
    while (i < n1 && j < n2) {
        ++count;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
        ++k;
    }
    
    // Copy remaining elements of L[], if any
    while (i < n1) {
        A[k] = L[i];
        ++i;
        ++k;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        A[k] = R[j];
        ++j;
        ++k;
    }
};

// Merge Sort function
_ mergeSort = [](_& A, _ p, _ r) {
    if (int(p) >= int(r)) { // explicitly casting to `int`
        return;
    }
    _ q = (int(p) + int(r)) / 2; // Casts might be needed elsewhere too
    mergeSort(A, p, q);       // Sort first half
    mergeSort(A, q + 1, r);   // Sort second half
    merge(A, p, q, r);        // Merge the sorted halves
};


int main() {
    _ A = get(range(100), 20); // Sample data
    print(A);

    mergeSort(A, 0, len(A) - 1); // Sort the array
    print(A);
    print("mergesort: ", count); // Print sorted array
    return 0;
}

