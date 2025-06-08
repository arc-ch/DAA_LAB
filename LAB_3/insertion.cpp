#include <iostream>
#include "cmm.H"
using namespace std;

int main() {
   // int A[] = {5, 2, 9, 1, 5, 6};
    //int n = sizeof(A)/sizeof(A[0]);
     _ A = get(range(1000), 100);
     print(A);
     _ count = 0;
     for (_ j = 1; j < len(A); ++j) {  // Start from the second element (index 1)
        _ key = A[j];
        _ i = j;
        while (i > 0 && A[i - 1] > key) {  // Shift elements of A[0..i-1] that are greater than key to one position ahead
            A[i] = A[i - 1];
            --i;
            ++count;
        }
        A[i] = key;  // Place key at the correct position
    }
    print(A);
    print("Comparisons: ", count);
    return 0;
}

