#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
//SOLUTION
void countDuplifindRepeating(vector<int>& arr) {
    unordered_map<int, int> map; // map = (value,freq)
    for (int num : arr) {
        map[num]++;
    }
    int maxFreq = 0; //store max freq for check condition
    int mostRepeatingElement;
    int duplicount = 0;
    
    for (auto& it : map) {   
        if (it.second > maxFreq) {  
            maxFreq = it.second;   //updating max freq value     
            mostRepeatingElement = it.first; // value
        }
        
        if (it.second > 1) { //for each iterator increase frequency count
            duplicount++;
        }
    }
    
    cout << "Most Repeating Element: " << mostRepeatingElement << " (Frequency: " << maxFreq << ")" << endl;
    cout << "Number of Duplicates: " << duplicount << endl;
}

int main() {    //INPUT
    vector<int> arr = {1, 3, 2, 4, 1, 3, 2, 3, 3};
    int n = arr.size();
    countDuplifindRepeating(arr);
    
    return 0;
}
