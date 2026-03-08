#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int sm = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sm += nums[i];
            maxi = max(maxi, sm);
            if (sm < 0) sm = 0;
        }
        sm = 0;
        for (int i = 0; i < nums.size(); i++) {
            sm += nums[i];
            mini = min(mini, sm);
            if (sm > 0) sm = 0;
        }
        
        return max(abs(maxi), abs(mini));
    }
};