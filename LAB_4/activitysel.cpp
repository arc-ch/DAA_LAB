#include<cmath>
#include"cmm.H"

int main() {
    // Activity selection problem
    	let A = {1, 8, 8, 1, 9, 1, 3};
    _ activities = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}}; // {start, finish}

    // Compare function to sort by finish time
    _ compareByFinishTime = [] (_ x, _ y) { return x[1] <= y[1]; };

    // Partition function for quicksort
    _ partition = [] (_& A, _ p, _ r, _ cmp) {
        _ x = A[r]; // Pivot element
        _ i = p; // Index of smaller element
        for (_ j = p; j < r; ++j) {
            if (cmp(A[j], x)) {
                swap(A[i], A[j]);
                ++i;
            }
        }
        swap(A[i], A[r]);
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
    _ greedyActivitySelection = [&] (_& s, _& f) {
        vec<_> A; // Define a vector to store selected activities
        _ i = 0;
        A <<= s[i]; // Selecting first activity

        for (_ j = 1; j < len(s); ++j) {
            if (f[i] <= s[j][0]) { 
                A <<= s[j];
                i = j; // Updating idx of last selected activity
            }
        }
        return A; // Return selected activities
    };

    // Sort activities by their finish times before applying the greedy selection
    quicksort(activities, 0, len(activities) - 1, quicksort);

    // Get the selected activities
    _ selectedActivities = greedyActivitySelection(activities, activities);
    print(selectedActivities);

    return 0;
}
