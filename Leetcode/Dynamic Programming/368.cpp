#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());          // FIX 1

        vector<int> dp(n, 1);                    // FIX 3
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        int maxi = 1;
        int last = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {    // FIX 2
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                last = i;
            }
        }

        vector<int> ans;
        while (parent[last] != last) {
            ans.push_back(nums[last]);
            last = parent[last];
        }
        ans.push_back(nums[last]);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};