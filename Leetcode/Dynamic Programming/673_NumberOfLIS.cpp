#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> ways(n, 1);
        int maxi = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    if(dp[i] < dp[j]+1) {
                        dp[i] = dp[j]+1;
                        ways[i] = ways[j];
                    }
                    else if(dp[i] == dp[j]+1) {
                        ways[i] += ways[j];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(dp[i] == maxi) {
                cnt += ways[i];
            }
        }

        return cnt;
    }
};