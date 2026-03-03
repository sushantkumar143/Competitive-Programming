#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for(int i=0; i<n; i++) pal[i][i] = true;
        for(int L=2; L<=n; L++) {
            for(int i=0; i+L-1<n; i++) {
                int j = i+L-1;

                // if(s[i] == s[j]) {
                //     if(L == 2) dp[i][j] = true;
                //     else if(dp[i+1][j-1]) dp[i][j] = true;
                // }
                if(s[i] == s[j] && (L == 2 || pal[i+1][j-1])) pal[i][j] = true;
                else pal[i][j] = false;
            }
        }

        vector<int> dp(n, INT_MAX);
        for(int i=0; i<n; i++) {
            if(pal[0][i]) dp[i] = 0;
            else  {
                for(int k=0; k<i; k++) {
                    if(pal[k+1][i] && 1+dp[k] < dp[i]) {
                        dp[i] = dp[k]+1;
                    }
                }
            }
        }

        return dp[n-1];
    }
};



// class Solution {
// public:
//     vector<vector<bool>> dp;
//     vector<vector<int>> cut;

//     int fun(int i, int j, string& s) {
//         if(i >= j) return 0;
//         if(dp[i][j]) return 0;

//         if(cut[i][j] != -1) return cut[i][j];

//         int ans = INT_MAX;

//         for(int k = i; k < j; k++) {
//             ans = min(ans, 1 + fun(i,k,s) + fun(k+1,j,s));
//         }

//         return cut[i][j] = ans;
//     }

//     int minCut(string s) {
//         int n = s.size();
//         dp.assign(n, vector<bool>(n, false));
//         cut.assign(n, vector<int>(n, -1));

//         for(int i=0; i<n; i++) dp[i][i] = true;

//         for(int L=2; L<=n; L++) {
//             for(int i=0; i+L-1<n; i++) {
//                 int j = i+L-1;

//                 if(s[i] == s[j]) {
//                     if(L == 2) dp[i][j] = true;
//                     else if(dp[i+1][j-1]) dp[i][j] = true;
//                 }
//                 else dp[i][j] = false;
//             }
//         }

//         return fun(0, n-1, s);
//     }
// };
