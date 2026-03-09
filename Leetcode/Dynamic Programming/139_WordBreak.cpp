#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    bool fun(int idx, int n, string& s, unordered_set<string>& st, vector<int>& dp) {
        if(idx == n) return true;
        if(dp[idx] != -1) return dp[idx];

        for(int i=idx+1; i<=n; i++) {
            string temp = s.substr(idx, i-idx);
            if(st.count(temp) && fun(i, n, s, st, dp)) return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        n = s.length();
        vector<int> dp(n, -1);

        return fun(0, n, s, st, dp);
    }
};