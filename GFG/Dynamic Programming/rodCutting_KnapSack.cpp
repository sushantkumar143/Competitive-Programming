#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution {
  public:
    int fun(int idx, int wt, vector<int>& price, vector<vector<int>>& dp) {
        if(!wt || idx<0) return 0;
        if(dp[idx][wt] != -1) return dp[idx][wt];
        
        int notTake = fun(idx-1, wt, price, dp);
        int take = 0;
        if(wt-(idx+1) >= 0) take = price[idx] + fun(idx, wt-(idx+1), price, dp);
        
        return dp[idx][wt] = max(notTake, take);
    }
  
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return fun(n-1, n, price, dp);
    }
};