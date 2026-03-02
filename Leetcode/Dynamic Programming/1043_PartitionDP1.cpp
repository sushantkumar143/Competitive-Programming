#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(int idx, int n, vector<int>& arr, int k, vector<int>& dp) {
        if(idx == arr.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int maxi = 0;
        int len = 0;
        int cost = 0;
        for(int i=idx; i<min(idx+k, n); i++) {
            len++;
            maxi = max(maxi, arr[i]);
            int temp = len*maxi + fun(i+1, n, arr, k, dp);
            cost = max(cost, temp);
        }
        return dp[idx] = cost;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return fun(0, n, arr, k, dp);
    }
};