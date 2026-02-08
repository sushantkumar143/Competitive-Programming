#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        int curr = 0;
        int maxIdx = 0;

        for(int i=0; i<n; i++) {
            if(maxIdx == n-1 || i==n-1) return true;
            maxIdx = max(maxIdx, i+nums[i]);
            if(i == curr) {
                curr = maxIdx;
            }
            if(maxIdx == i) return false;
        }

        return true;
    }
};