#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main() {
    // Define the activities with start and finish times
    auto activities = vector<pair<int, int>>{{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};

    // Lambda function to compare activities by their finish time
    auto compareByFinishTime = [] (const auto& x, const auto& y) {
        return x.second < y.second;
    };

    // Partition function for quicksort
    auto partition = [] (auto& A, auto p, auto r, const auto& cmp) {
        auto pivot = A[r]; // Pivot element
        auto i = p; // Index of smaller element
        for (auto j = p; j < r; ++j) {
            if (cmp(A[j], pivot)) {
                swap(A[i], A[j]);
                ++i;
            }
        }
        swap(A[i], A[r]);
        return i;
    };

    // Quicksort function with std::function to enable recursion
    function<void(vector<pair<int, int>>&, int, int, const decltype(compareByFinishTime)&)> quicksort;
    quicksort = [&] (auto& A, auto p, auto r, const auto& cmp) {
        if (p < r) {
            auto q = partition(A, p, r, cmp);
            quicksort(A, p, q - 1, cmp);
            quicksort(A, q + 1, r, cmp);
        }
    };

    // Sort the activities by finish time
    quicksort(activities, 0, activities.size() - 1, compareByFinishTime);

    // Greedy algorithm for activity selection
    auto greedyActivitySelection = [] (const auto& sortedActivities) {
        auto selectedActivities = vector<pair<int, int>>{};
        selectedActivities.push_back(sortedActivities[0]); // Select the first activity

        auto lastSelected = 0;
        for (auto j = 1; j < sortedActivities.size(); ++j) {
            if (sortedActivities[lastSelected].second <= sortedActivities[j].first) {
                selectedActivities.push_back(sortedActivities[j]);
                lastSelected = j; // Update the last selected activity index
            }
        }
        return selectedActivities;
    };

    // Get the selected activities after sorting by finish time
    auto selectedActivities = greedyActivitySelection(activities);

    // Print the selected activities
    for (const auto& activity : selectedActivities) {
        cout << "{" << activity.first << ", " << activity.second << "} ";
    }

    return 0;
}

