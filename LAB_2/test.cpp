#include <iostream>
#include <algorithm> // for std::swap
#include <string>
#include <bitset>
#include "cmm.H"
//#include "home\kiit\SEM_5\DAA_LAB\LAB_2\cmm.H"

// Assuming that print is a function in cmm.H
void print(const std::string& value) {
    std::cout << "The binary representation is: " << value << std::endl;
}

// Define the toBinary function
std::string toBinary(int n, int i) {
    if (i > 1) {
        return toBinary(n / 2, i - 1) + std::to_string(n % 2);
    } else {
        return std::to_string(n % 2);
    }
}

int main() {
    int number = 2564;
    int bits = 16;

    // Compute the binary representation
    std::string binary = toBinary(number, bits);

    print(binary);

    return 0;
}



// #include <iostream>
// #include "cmm.H"
// using namespace std;

// int main() {
//    // int A[] = {5, 2, 9, 1, 5, 6};
//     //int n = sizeof(A)/sizeof(A[0]);
//      _ A = get(range(100), 20);
//      print(A);
//      _ count = 0;
//      for (_ j = 1; j < len(A); ++j) {  // Start from the second element (index 1)
//         _ key = A[j];
//         _ i = j;
//         while (i > 0 && A[i - 1] > key) {  // Shift elements of A[0..i-1] that are greater than key to one position ahead
//             A[i] = A[i - 1];
//             --i;
//             ++count;
//         }
//         A[i] = key;  // Place key at the correct position
//     }
//     print(A);
//     print(count);
//     return 0;
// }
