#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(int i, int j, string& s, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = 2 + fun(i+1, j-1, s, dp);
        return dp[i][j] = max(fun(i+1, j, s, dp), fun(i, j-1, s, dp));
    }

    // int longestPalindromeSubseq(string s) {
    //     int n = s.length();
    //     vector<vector<int>> dp(n, vector<int>(n, -1));
    //     return fun(0, n-1, s, dp);
    // }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=0; i<n; i++) dp[i][i] = 1;

        for(int L=2; L<=n; L++) {
            for(int i=0; i+L-1<n; i++) {
                int j = i+L-1;

                if(s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return dp[0][n-1];
    }
};