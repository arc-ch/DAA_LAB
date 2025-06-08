#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    // Example matrix dimensions: For matrices A1 (4x2), A2 (2x3), A3 (3x1), A4 (1x3)
    vector<int> mat = {40, 20, 30, 10, 30};  // Dimensions array
    //printf("bruh");
    int n = mat.size() - 1;  // Number of matrices

    // 2D array to store the minimum multiplication costs
    vector<vector<int>> m(n, vector<int>(n, 0));

    // Array to store the split points for the optimal solution
    vector<vector<int>> s(n, vector<int>(n, 0));

    // Initialize the cost of multiplying a single matrix (diagonal of the matrix is 0)
    for (int i = 0; i < n; i++) {
        m[i][i] = 0;
    }

    // l is the chain length, starting from 2 to n
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;  // The index of the last matrix in the current chain
            m[i][j] = INT_MAX;  // Initialize to infinity (we'll look for the minimum)

            // Try every possible place to split the product (from i to j)
            for (int k = i; k < j; k++) {
                // Calculate cost of multiplying matrices from i to j
                int cost = m[i][k] + m[k + 1][j] + mat[i] * mat[k + 1] * mat[j + 1];

                // If this split gives a lower cost, update m[i][j] and store split point
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;  // Store split point
                }
            }
        }
    }

    // Print the minimum cost
    cout << "Minimum number of multiplications is: " << m[0][n - 1] << endl;

    // Print matrix split points for optimal cost
    cout << "Optimal split points:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != 0)
                cout << "For matrices between " << i + 1 << " and " << j + 1 << ", split at matrix " << s[i][j] + 1 << endl;
        }
    }

    return 0;
}
