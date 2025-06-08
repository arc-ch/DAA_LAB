#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Min priority queue using a lambda comparator
    priority_queue<int, vector<int>, greater<int>> minPQ;

    // Adding elements to the min priority queue
    minPQ.push(10);
    minPQ.push(5);
    minPQ.push(20);
    minPQ.push(1);

    // Printing and removing elements from the min priority queue
    cout << "Elements in the min priority queue: ";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << endl;

    return 0;
}

