#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    // Create a (m+1) x (n+1) matrix initialized to 0
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    // Fill the matrix according to the LCS algorithm
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    // Return the length of LCS found at c[m][n]
    return c[m][n];
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCAB";

    int lcsLength = longestCommonSubsequence(X, Y);
    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;

    return 0;
}

