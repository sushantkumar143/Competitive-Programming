#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    int total;

    int fun(int idx, int sum, vector<int>& nums, int target, vector<vector<int>>& dp) {

        if(idx == n)
            return sum == target;

        if(dp[idx][sum + total] != -1)
            return dp[idx][sum + total];

        int add = fun(idx + 1, sum + nums[idx], nums, target, dp);
        int sub = fun(idx + 1, sum - nums[idx], nums, target, dp);

        return dp[idx][sum + total] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));

        return fun(0, 0, nums, target, dp);
    }
};