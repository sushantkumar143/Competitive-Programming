#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> dp;

//     int fun(int idx, vector<int>& nums) {
//         if (idx == 0) return 0;
//         if (dp[idx] != -1) return dp[idx];

//         int ways = 1e9;

//         for (int i = 0; i < idx; i++) {
//             if (i + nums[i] >= idx) {
//                 ways = min(ways, 1 + fun(i, nums));
//             }
//         }

//         return dp[idx] = ways;
//     }

//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         dp.assign(n, -1);
//         return fun(n - 1, nums);
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int currIdx = 0;
        int maxIdx = 0;
        int jumps = 0;

        for(int i=0; i<n-1; i++) {
            maxIdx = max(maxIdx, i + nums[i]);

            if(currIdx == i) {
                jumps++;
                currIdx = maxIdx;
            }
        }

        return jumps;
    }
};