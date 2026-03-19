#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fun(int idx, int n, int& ans, vector<int>& temp, vector<int>& cookies, int k) {
        if(idx == n) {
            int maxi = INT_MIN;
            for(int& x : temp) {
                maxi = max(maxi, x);
            }
            ans = min(ans, maxi);
            return; 
        }

        for(int i=0; i<k; i++) {
            temp[i] += cookies[idx];
            fun(idx+1, n, ans, temp, cookies, k);
            temp[i] -= cookies[idx];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int ans = INT_MAX;
        vector<int> temp(k, 0);
        fun(0, n, ans, temp, cookies, k);
        return ans;
    }
};