#include <iostream>
#include <vector>
using namespace std;

int knapsack(const vector<int>& v, const vector<int>& w, int W) {
    int n = w.size();
    vector<vector<int>> m(n + 1, vector<int>(W + 1, 0));

    // Build table m[][] in a bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (w[i - 1] <= j) {
                m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i - 1]] + v[i - 1]);
            } else {
                m[i][j] = m[i - 1][j];
            }
        }
    }

    return m[n][W];  // Return the maximum value
}

int main() {
    vector<int> v = {60, 100, 120};  // Values
    vector<int> w = {10, 20, 30};    // Weights
    int W = 50;                      // Knapsack capacity

    cout << "Maximum value in Knapsack = " << knapsack(v, w, W) << endl;
    return 0;
}

