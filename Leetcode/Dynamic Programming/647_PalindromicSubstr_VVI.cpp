#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool isPalindrome(int i, int j, string& s) {
    //     while(i <= j) {
    //         if(s[i] != s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    bool isPalindrome(int i, int j, string& s, vector<vector<int>>& dp) {
        if(i > j) return true;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = isPalindrome(i+1, j-1, s, dp);
        return dp[i][j] = false;
    }

    // int countSubstrings(string s) {
    //     int n = s.length();
    //     int cnt = 0;
    //     vector<vector<int>> dp(n, vector<int>(n, -1));

    //     for(int i=0; i<n; i++) {
    //         for(int j=i; j<n; j++) {
    //             if(isPalindrome(i, j, s, dp)) cnt++;
    //         }
    //     }

    //     return cnt;
    // }

    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int L=1; L<=n; L++) {
            for(int i=0; i+L-1 < n; i++) {
                int j = i+L-1;

                if(i == j) dp[i][j] = true;
                else if(s[i] == s[j] && L==2) dp[i][j] = true;
                else if(s[i] == s[j] && dp[i+1][j-1]) dp[i][j] = true;
                else dp[i][j] = false;
            
                if(dp[i][j]) cnt++;
            }
        }

        return cnt;
    }
};