#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1?page=1&category=Recursion,Backtracking&sortBy=submissions

class Solution {
  public:
    int n;
    
    void fun(int idx, string &s, vector<string> &ans) {
        if (idx == n) {
            ans.push_back(s);
            return;
        }
        
        bool used[26] = {false}; 
        
        for (int i = idx; i < n; i++) {
            int ch = s[i] - 'A'; 
            if (used[ch]) continue;
            
            used[ch] = true;
            swap(s[i], s[idx]);
            fun(idx + 1, s, ans);
            swap(s[i], s[idx]);
        }
    }
    
    vector<string> findPermutation(string &s) {
        sort(s.begin(), s.end());  
        n = s.size();
        vector<string> ans;
        fun(0, s, ans);
        return ans;
    }
};