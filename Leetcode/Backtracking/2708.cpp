#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long ans = LLONG_MIN;

    void dfs(int i, vector<int>& nums, long long prod, bool taken) {
        if(i == nums.size()) {
            if(taken)
                ans = max(ans, prod);
            return;
        }

        // Take
        dfs(i+1, nums, prod * nums[i], true);

        // Not take
        dfs(i+1, nums, prod, taken);
    }

    long long maxStrength(vector<int>& nums) {
        dfs(0, nums, 1, false);
        return ans;
    }
};
