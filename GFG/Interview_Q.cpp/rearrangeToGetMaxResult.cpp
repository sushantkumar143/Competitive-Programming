// https://www.geeksforgeeks.org/problems/reaching-the-heights1921/1

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> rearrange(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        vector<int> result(n);
        int left = 0;
        int right = n - 1;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                result[i] = arr[right];
                right--;
            } 
            else {
                result[i] = arr[left];
                left++;
            }
        }
        
        return result;
    }
};