#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1?page=1&category=Recursion,Backtracking&sortBy=submissions

class Solution {
  public:
    
    void solve(stack<int>& s, int k) {
        if(k == 0) {
            s.pop();   
            return;
        }
        
        int top = s.top();
        s.pop();
        solve(s, k - 1);
        s.push(top);
    }
    
    void deleteMid(stack<int>& s) {
        int n = s.size();
        int k = n / 2;   
        solve(s, k);
    }
};