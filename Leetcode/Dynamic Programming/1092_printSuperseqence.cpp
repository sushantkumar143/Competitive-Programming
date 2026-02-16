#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i-1] == str2[j-1]) {          // FIX 1
                    dp[i][j] = 1 + dp[i-1][j-1];
                } 
                else {
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string s = "";
        int i = n, j = m;

        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                s += str1[i-1];
                i--; j--;
            }
            else if(dp[i-1][j] < dp[i][j-1]) {
                s += str1[i-1];    // FIX 2
                i--;
            }
            else {
                s += str2[j-1];    // FIX 2
                j--;
            }
        }

        // FIX 3: add remaining characters
        while(i > 0) {
            s += str1[i-1];
            i--;
        }
        while(j > 0) {
            s += str2[j-1];
            j--;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};




// LENGTH OF SHRTEST SUPERSEQENCE

class Solution {
  public:
    int fun(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + fun(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] =  1 + min(fun(i-1, j, s1, s2, dp), fun(i, j-1, s1, s2, dp));
    }
  
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return fun(n-1, m-1, s1, s2, dp);
    }
};



// class Solution {
//   public:
//     int fun(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
//         if(i<0 || j<0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
        
//         if(s1[i] == s2[j]) return dp[i][j] = 1 + fun(i-1, j-1, s1, s2, dp);
        
//         return dp[i][j] = max(fun(i-1, j, s1, s2, dp), fun(i, j-1, s1, s2, dp));
//     }
  
//     int minSuperSeq(string &s1, string &s2) {
//         // code here
//         int n = s1.length();
//         int m = s2.length();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
//         int lcs = fun(n-1, m-1, s1, s2, dp);
        
//         return n + m - lcs;
//     }
// };