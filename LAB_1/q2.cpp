#include <iostream>
#include <vector>
using namespace std;

vector<int> calculatePrefixSum(vector<int>& arr) {
    int n;
    vector<int> prefixSum(n,0);
    prefixSum[0] = arr[0];   //storing first value in prefixsum array to be used later

    for (int i = 1; i < n; ++i) 
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];     //i=1 => prefixsum[1-1]+arr[1], i=2 => prefixsum[2-1]+arr[2] 
    }
    return prefixSum;
}

int main() {
    vector<int> arr = {3, 4, 5, 1, 2};
    int n = arr.size();
    vector<int> prefixSum = calculatePrefixSum(arr);
    
    cout << "Input Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Output Array (Prefix Sum): ";
    for (int sum : prefixSum) {
        cout << sum << " ";
    }
    cout << endl;
    
    return 0;
}
