#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;

    void fun(int idx, string& s, vector<string>& temp, vector<vector<bool>>& dp) {
        if(idx == s.length()) {
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<s.length(); i++) {
            if(dp[idx][i]) {
                temp.push_back(s.substr(idx, i-idx+1));
                fun(i+1, s, temp, dp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++) dp[i][i] = true;

        for(int L=2; L<=n; L++) {
            for(int i=0; i+L-1<n; i++) {
                int j = i+L-1;

                if(s[i] == s[j]) {
                    if(L == 2) dp[i][j] = true;
                    else if(dp[i+1][j-1]) dp[i][j] = true;
                }
                else dp[i][j] = false;
            }
        }

        vector<string> temp;
        fun(0, s, temp, dp);
        return ans;
    }
};
