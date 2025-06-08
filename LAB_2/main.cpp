// #include <iostream>
// #include <algorithm> // for std::swap
// #include "cmm.H" 

// // Assuming that print is a function in cmm.H
// void print(int value) {
//     std::cout << "The value is: " << value << std::endl;
// }

// int main() {
//     // Initialize variables
//     int a = 84, b = 126;

//     // Define a lambda function to compute gcd
//     auto gcd = [] (int a, int b) {
//         while (b != 0) {
//             a = a % b;
//             std::swap(a, b);
//         }
//         return a;
//     };

//     // Compute gcd and print the result
//     int result = gcd(a, b);
//     print(result);

//     return 0;
// }


 
#include <iostream>
#include "cmm.H"

int main() {
//    let a = 84, b = 126;
  //  print(a);
  _ gcd = [] (_ a, _ b)
  { 
    while(b!=0)
    {
       a=a%b;
       std::swap(a,b);
    }
  return a;
  //print(a, b);
  };
  
  print(gcd(84, 126));
  return 0;
}


