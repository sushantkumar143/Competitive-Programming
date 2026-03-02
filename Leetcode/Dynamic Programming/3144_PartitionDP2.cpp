#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(int idx, int n, string& s, vector<int>& dp) {
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int distinct = 0;
        int maxFreq = 0;
        int cost = INT_MAX;
        int freq[26] = {0};
        
        for(int i=idx; i<n; i++) {
            int ch = s[i]-'a';
            if(freq[ch] == 0) distinct++;
            freq[ch]++;
            maxFreq = max(maxFreq, freq[ch]);
            int len = i-idx+1;

            if(len == distinct*maxFreq) {
                cost = min(cost, 1 + fun(i+1, n, s, dp));
            }
        }

        return dp[idx] = cost;
    }

    int minimumSubstringsInPartition(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return fun(0, n, s, dp);
    }
};



// class Solution {
// public:
//     bool check(int i, int j, string& s) {
//         unordered_map<char, int> mp;
//         for(int k=i; k<=j; k++) {
//             mp[s[k]]++;
//         }
//         int prev = -1;
//         for(auto i : mp) {
//             if(prev == -1) prev = i.second;
//             else if (i.second != prev) return false;
//         }
//         return true;
//     }

//     int fun(int idx, int n, string& s, vector<int>& dp) {
//         if(idx == n) return 0;
//         if(dp[idx] != -1) return dp[idx];

//         int cost = INT_MAX;
//         for(int i=idx; i<n; i++) {
//             if(check(idx, i, s)) {
//                 cost = min(cost, 1 + fun(i+1, n, s, dp));
//             }
//         }
//         return dp[idx] = cost;
//     } 

//     int minimumSubstringsInPartition(string s) {
//         int n = s.length();
//         vector<int> dp(n, -1);
//         return fun(0, n, s, dp);
//     }
// };