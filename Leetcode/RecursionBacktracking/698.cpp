#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool fun(int idx, int sm, vector<int>& nums, int k, int target, vector<bool>& vis) {
        if (k == 1) return true; 
        if (sm == target)
            return fun(0, 0, nums, k - 1, target, vis);

        for (int i = idx; i < nums.size(); i++) {
            if (vis[i] || sm + nums[i] > target) continue;

            // skip duplicates
            if (i > idx && nums[i] == nums[i - 1] && !vis[i - 1]) continue;

            vis[i] = true;
            if (fun(i + 1, sm + nums[i], nums, k, target, vis))
                return true;
            vis[i] = false;

            // pruning: first element fails → no need to try others
            // if (sm == 0) return false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sm = accumulate(nums.begin(), nums.end(), 0);
        if (sm % k != 0) return false;

        int target = sm / k;
        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target) return false;

        vector<bool> vis(nums.size(), false);
        return fun(0, 0, nums, k, target, vis);
    }
};
