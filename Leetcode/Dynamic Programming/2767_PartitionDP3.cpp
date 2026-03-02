#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOf5(long long num) {
        if(num <= 0) return false;
        while(num % 5 == 0) num /= 5;
        return num == 1;
    }

    int solve(int i, string &s, vector<int> &dp) {
        if(i == s.length()) return 0;
        if(dp[i] != -1) return dp[i];

        if(s[i] == '0') return dp[i] = 1e9; 

        long long num = 0;
        int ans = 1e9;

        for(int j = i; j < s.length(); j++) {
            num = num * 2 + (s[j] - '0');

            if(isPowerOf5(num)) {
                ans = min(ans, 1 + solve(j+1, s, dp));
            }
        }

        return dp[i] = ans;
    }

    int minimumBeautifulSubstrings(string s) {
        vector<int> dp(s.length(), -1);
        int res = solve(0, s, dp);
        return res >= 1e9 ? -1 : res;
    }
};