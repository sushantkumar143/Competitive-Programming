#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPredecessor(string &s1, string &s2) {
        if(s2.size() - s1.size() != 1) return false;

        int i = 0, j = 0;
        while(i < s1.size() && j < s2.size()) {
            if(s1[i] == s2[j]) {
                i++; j++;
            } 
            else {
                j++;
            }
        }
        return i == s1.size();
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(),
             [](auto &a, auto &b){ return a.size() < b.size(); });

        int n = words.size();
        vector<int> dp(n, 1);

        int ans = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(checkPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};



// class Solution {
// public:
//     bool checkPredecessor(string s1, string s2) {
//         int n = s1.length();
//         int m = s2.length();

//         if(abs(n-m) != 1) return false;

//         int i=0;
//         int j=0;
//         while(i<n && j<m) {
//             if(s1[i] == s2[j]) {
//                 i++;
//                 j++;
//             }
//             else {
//                 i++;
//             }
//         }

//         return j == m;
//     }

//     int fun(int idx, int prev, vector<string>& words, vector<vector<int>>& dp) {
//         if(idx > words.size()) return 0;
//         if(dp[idx][prev] != -1) return dp[idx][prev];

//         int notTake = fun(idx+1, prev, words, dp);
//         int take = 0;
//         if(prev == 0 || checkPredecessor(words[idx-1], words[prev-1])) {
//             take = 1 + fun(idx+1, idx, words, dp);
//         }

//         return dp[idx][prev] = max(take, notTake);
//     }

//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(), words.end(), [](const string& s1, const string& s2) {
//             return s1.length() < s2.length();
//         });

//         int n = words.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

//         return fun(1, 0, words, dp);
//     }
// };