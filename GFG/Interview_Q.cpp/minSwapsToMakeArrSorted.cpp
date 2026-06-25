#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        vector<int> temp(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int n = arr.size();
        sort(temp.begin(), temp.end());
        int swaps = 0;
        
        for(int i=0; i<n; i++) {
            mp[arr[i]] = i;
        }
        
        for(int i=0; i<n; i++) {
            if(arr[i] != temp[i]) {
                
                int ind = mp[temp[i]];
                swap(arr[i], arr[ind]);
                
                mp[arr[ind]] = ind;
                mp[arr[i]] = i;
                swaps++;
            }
        }
        
        return swaps;
    }
};