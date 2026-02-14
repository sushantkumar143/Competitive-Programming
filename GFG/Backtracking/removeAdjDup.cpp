#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1?page=1&category=Recursion,Backtracking&sortBy=submissions

class Solution {
  public:
    string removeUtil(string s) {
        int n = s.length();
        if(n <= 1) return s;

        string res = "";
        int i = 0;

        while(i < n) {
            int j = i;
            while(j + 1 < n && s[j] == s[j + 1]) j++;

            if(j == i) {
                res.push_back(s[i]);
            }
            i = j + 1;
        }

        if(res.length() == s.length())
            return res;             

        return removeUtil(res);   
    }
};