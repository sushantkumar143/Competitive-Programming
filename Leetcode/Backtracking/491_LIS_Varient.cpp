#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fun(int idx, int n, int prev, vector<int>& nums, set<vector<int>>& ans, vector<int>& temp) {
        if(idx == n) {
            if(temp.size() > 1) ans.insert(temp);
            return;
        }

        fun(idx+1, n, prev, nums, ans, temp);
        if(prev <= nums[idx]) {
            temp.push_back(nums[idx]);
            fun(idx+1, n, nums[idx], nums, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        vector<int> temp;
        fun(0, n, INT_MIN, nums, ans, temp);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};