#include<bits/stdc++.h>
using namespace std;

// IT IS ALSO A PROBLEM OF SORTING  -- GOOD Q. -- BIT MIDIUM LEVEL

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int left = 0;
        int maxLen = 1;

        for(int right = 0; right < n; right++) {
            while((long long)nums[right] > (long long)nums[left] * k) {
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return n - maxLen;
    }
};