#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();

        vector<int> ans(n);
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            
            ans[i] = st.empty() ? i+1 : i - st.top();
            
            st.push(i);
        }
        
        return ans;
        
    }
};