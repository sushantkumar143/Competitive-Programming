#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    long long dp[100005][3][4];
    
    long long fun(int idx, string& s, int prev, int len) {
        if(len == 3) return 1;
        if(idx == n) return 0;
        if(dp[idx][prev][len] != -1) return dp[idx][prev][len];

        long long notTake = fun(idx+1, s, prev, len);
        int curr = s[idx] - '0';
        long long take = 0;
        if(len==0 || prev != curr) take += fun(idx+1, s, curr, len+1);

        return dp[idx][prev][len] = take + notTake;
    }

    long long numberOfWays(string s) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return fun(0, s, 2, 0);
    }
};