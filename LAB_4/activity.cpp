#include <cmath>
#include "cmm.H"
#include <vector>

int main() {
    // Activity selection problem
    let activities = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}}; // {start, finish}

    // Compare function to sort by finish time
    _ compareByFinishTime = [] (_ x, _ y) { return x[1] <= y[1]; };

    // Partition function for quicksort
    _ partition = [] (_& A, _ p, _ r, _ cmp) {
        _ x = A[r]; // Pivot element
        _ i = p; // Index of smaller element
        for (_ j = p; j < r; ++j) {
            if (cmp(A[j], x)) {
                std::swap(A[i], A[j]);
                ++i;
            }
        }
        std::swap(A[i], A[r]);
        return i;
    };

    // Quicksort function
    _ quicksort = [&] (_& A, _ p, _ r, _ f) -> void {
        if (p < r) {
            _ q = partition(A, p, r, compareByFinishTime);
            f(A, p, q - 1, f);
            f(A, q + 1, r, f);
        }
    };

    // Greedy algorithm for activity selection
    _ greedyActivitySelection = [&] (_& activities) 
    {
        std::vector<decltype(activities[0])> selectedActivities; // Result vector to store selected activities
        _ i = 0;
        selectedActivities.push_back(activities[i]); // Selecting first activity

        for (_ j = 1; j < len(activities); ++j) {
            if (activities[i][1] <= activities[j][0]) { 
                selectedActivities.push_back(activities[j]);
                i = j; // Updating idx of last selected activity
            }
        }
        return selectedActivities; // Return selected activities
    };

    // Sort activities by their finish times before applying the greedy selection
    quicksort(activities, 0, len(activities) - 1, quicksort);

    // Get the selected activities
    let selectedActivities = greedyActivitySelection(activities);
    print(selectedActivities);

    return 0;
}
