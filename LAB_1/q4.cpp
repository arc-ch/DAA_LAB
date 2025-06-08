#include <iostream>
using namespace std;

// exchange function the numbers p & q
void EXCHANGE(int &p, int &q) { 
    int temp = p;
    p = q;
    q = temp;
}
void ROTATE_RIGHT(int p1[], int p2) {
    int last = p1[p2 - 1];  //storing last val to be kept at 0th pos at the end

    // Swapping till i=1
    for (int i = p2 - 1; i > 0; i--)  {EXCHANGE(p1[i], p1[i - 1]);}

    //putting prev 5th value at 0th pos     
    p1[0] = last;
}

int main() {
    int A[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int N = sizeof(A) / sizeof(A[0]);
    int p2 = 5;

    cout << "Before ROTATE: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    ROTATE_RIGHT(A, p2);

    cout << "After ROTATE: ";
    for (int i = 0; i < N; i++)  {cout << A[i] << " ";}
    return 0;
}