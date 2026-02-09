#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-four-sum-subsequence/1

class Solution {
  public:
    int fun(int i, vector<int>& arr, vector<int>& dp) {
        if (i < 0) return 1e9;    
        if (dp[i] != -1) return dp[i];

        if (i < 4) {
            return dp[i] = arr[i];
        }

        return dp[i] = arr[i] + min({
            fun(i - 1, arr, dp),
            fun(i - 2, arr, dp),
            fun(i - 3, arr, dp),
            fun(i - 4, arr, dp)
        });
    }

    int minSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);

        int ans = 1e9;
        for (int i = n - 1; i >= max(0, n - 4); i--) {
            ans = min(ans, fun(i, arr, dp));
        }
        return ans;
    }
};