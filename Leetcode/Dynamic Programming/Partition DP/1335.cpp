#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(int idx, int n, vector<int>& jobDifficulty, int d, vector<vector<int>>& dp) {
        if (n - idx < d) return INT_MAX;
        if(d == 1) {
            int maxi = jobDifficulty[idx];
            for(int i = idx; i < n; i++)
                maxi = max(maxi, jobDifficulty[i]);
            return maxi;
        }
        if(dp[idx][d] != -1) return dp[idx][d];

        long long cost = INT_MAX;
        long long maxi = jobDifficulty[idx];

        for(int i = idx; i < n; i++) {
            maxi = max(maxi, (long long)jobDifficulty[i]);

            int next = fun(i+1, n, jobDifficulty, d-1, dp);

            if (next != INT_MAX) {
                cost = min(cost, maxi + next);
            }
        }

        return dp[idx][d] = (int)cost;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        vector<vector<int>> dp(n, vector<int>(d+1, -1));

        return fun(0, n, jobDifficulty, d, dp);
    }
};