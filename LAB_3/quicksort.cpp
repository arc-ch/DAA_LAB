// #include <iostream>
// #include "cmm.H"
// //using namespace std;

// // void swap(_& a, _& b) {
// //     _ temp = a;
// //     a = b;
// //     b = temp;
// // }

// int main() {
//     _ A = get(range(100), 20); // Sample data
//     _ count = 0;
// _ partition = [&](_& A, _ p, _ r) {

#include <iostream>
#include "cmm.H"
using namespace std; // Added to use std::swap

// Function to swap elements
//void swap(_& a, _& b) {
//    _ temp = a;
//    a = b;
//    b = temp;
//}

int main() {
    _ A = get(range(100), 20); // Sample data
    print(A);
    _ count = 0;
    
    // Partition function as a lambda
    auto partition = [&](_& A, _ p, _ r) -> _ {
        _ x = A[r]; // Pivot element
        _ i = p; // Index of smaller element
        for (_ j = p; j < r; ++j) {
            ++count;
            if (A[j] <= x) {
                std::swap(A[i], A[j]);
                ++i;
            }
        }
        std::swap(A[i], A[r]);
        return i;
    };

    // Quick Sort function as a lambda
    auto quickSortLambda = [&]( _& A, _ p, _ r, auto& self) -> void {
        if (p < r) {
            _ q = partition(A, p, r);
            self(A, p, q - 1, self);
            self(A, q + 1, r, self);
            

        }
    };
    
    // Calling quickSortLambda lambda function
    quickSortLambda(A, 0, len(A) - 1, quickSortLambda);
    
    // Print the result and count
    print(A);
    print("quicksort: ", count, "steps"); // Assuming `print` is a function for output
    return 0;
}

