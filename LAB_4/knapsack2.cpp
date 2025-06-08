#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Partition function for quicksort
int partition(vector<pair<int, int>>& A, int p, int r) {
    auto x = A[r]; // Pivot element
    int i = p;     // Index of smaller element
    for (int j = p; j < r; ++j) {
        if (A[j].first / (double)A[j].second <= x.first / (double)x.second) {
            swap(A[i], A[j]);
            ++i;
        }
    }
    swap(A[i], A[r]);
    return i;
}

// Quicksort function
void quicksort(vector<pair<int, int>>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

// Greedy fractional knapsack function
vector<pair<pair<int, int>, int>> greedyFractionalKnapsack(vector<pair<int, int>>& items, int w) {
    quicksort(items, 0, items.size() - 1);

    vector<pair<pair<int, int>, int>> result; //result vector-> {{price, weight}, qty}
    int remaining = w;

    while (remaining > 0 && !items.empty()) {
        auto best = items.back();
        items.pop_back();

        int qty = min(best.second, remaining);
        result.push_back({best, qty});

        remaining -= qty;
    }
    return result;
}

int main() {
    vector<pair<int, int>> data = {{10, 2}, {5, 3}, {15, 5}, {7, 7}, {3, 1}}; // {price, weight}

    auto result = greedyFractionalKnapsack(data, 10);

    // Print the result in the desired format
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[[" << result[i].first.first << ", " << result[i].first.second << "], " << result[i].second << "]";
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}



/*
| **Iteration** | **Popped Item (price, weight)** | **Quantity Taken** | **Remaining Capacity** | **Resulting Items in Knapsack**                       |
|---------------|---------------------------------|--------------------|------------------------|------------------------------------------             |
| 1             | {10, 2}                         | 2                  | 8                      | {{10, 2}, 2}                             	       |
| 2             | {3, 1}                          | 1                  | 7                      | {{10, 2}, 2}, {{3, 1}, 1}                	       |
| 3             | {15, 5}                         | 5                  | 2                      | {{10, 2}, 2}, {{3, 1}, 1}, {{15, 5}, 5}              |
| 4             | {5, 3}                          | 2 (partial)        | 0                      | {{10, 2}, 2}, {{3, 1}, 1}, {{15, 5}, 5}, {{5, 3}, 2} |
*/

