#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Partition function for quicksort (for sorting by finish times)
int partition(vector<pair<int, int>>& A, int p, int r) {
    auto x = A[r]; // Pivot element
    int i = p;     // Index of smaller element
    for (int j = p; j < r; ++j) {
        if (A[j].second <= x.second) { // Compare by finish time
            swap(A[i], A[j]);
            ++i;
        }
    }
    swap(A[i], A[r]);
    return i;
}

// Quicksort function (sorting by finish times)
void quicksort(vector<pair<int, int>>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

// Greedy function for activity selection
vector<pair<int, int>> greedyActivitySelector(vector<pair<int, int>>& activities) {
    quicksort(activities, 0, activities.size() - 1);

    vector<pair<int, int>> result;
    int lastFinishTime = -1;

    for (const auto& activity : activities) {
        if (activity.first > lastFinishTime) {
            result.push_back(activity);
            lastFinishTime = activity.second;
        }
    }
    return result;
}

int main() {
    vector<pair<int, int>> activities = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};

    auto result = greedyActivitySelector(activities);

    // Print the result in the desired format
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[[" << result[i].first << ", " << result[i].second << "]]";
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

//result => [[[1, 4]], [[5, 7]], [[8, 11]], [[12, 14]]]

    return 0;
}

