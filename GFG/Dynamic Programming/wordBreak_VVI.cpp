#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/word-break1352/1

// class Solution {
//   public:
    // bool fun(int idx, string &s, unordered_set<string>& st, vector<int>& dp) {
    //     if(idx == s.size()) return true;
    //     if(dp[idx] != -1) return dp[idx];
        
    //     string temp = "";
    //     for(int i=idx; i<s.length(); i++) {
    //         temp.push_back(s[i]);
    //         if(st.count(temp)) {
    //             if(fun(i+1, s, st, dp)) return dp[idx] = true;
    //         }
    //     }
        
    //     return dp[idx] = false;
    // }
    
  
    // bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        // vector<int> dp(s.length(), -1);
        // unordered_set<string> st(dictionary.begin(), dictionary.end());
        
        // return fun(0, s, st, dp);
        
        
//         int n = s.size();
//         unordered_set<string> dict(dictionary.begin(), dictionary.end());

//         vector<bool> dp(n + 1, false);
//         dp[0] = true;

//         for (int i = 1; i <= n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (dp[j] && dict.count(s.substr(j, i - j))) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[n];
//     }
// };



class Solution {
  public:
    bool fun(int idx, string &s, unordered_set<string>& st,
             vector<int>& dp, int maxLen) {

        if (idx == s.size()) return true;
        if (dp[idx] != -1) return dp[idx];

        string temp = "";
        int n = s.size();

        for (int i = idx; i < n && i - idx + 1 <= maxLen; i++) {
            temp.push_back(s[i]);
            if (st.count(temp)) {
                if (fun(i + 1, s, st, dp, maxLen))
                    return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string &s, vector<string> &dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        int maxLen = 0;
        for (auto &w : dictionary)
            maxLen = max(maxLen, (int)w.size());

        vector<int> dp(s.size(), -1);
        return fun(0, s, st, dp, maxLen);
    }
};