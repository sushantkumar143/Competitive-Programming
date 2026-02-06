#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int ans = 0;
        int left = 0;

        for(int right=0; right<nums.size(); right++) {
            if(!nums[right]) zeros++;
            while(left <= right && zeros > k) {
                if(!nums[left]) zeros--;
                left++;
            } 
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};