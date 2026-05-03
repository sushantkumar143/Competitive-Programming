#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        int ans = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> dp;
//     int ans = 0;

//     int fun(int i, int j, vector<int>& nums1, vector<int>& nums2) {
//         if(i < 0 || j < 0) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         int len = 0;

//         if(nums1[i] == nums2[j]) {
//             len = 1 + fun(i-1, j-1, nums1, nums2);
//             ans = max(ans, len);
//         }

//         // still explore all states
//         fun(i-1, j, nums1, nums2);
//         fun(i, j-1, nums1, nums2);

//         return dp[i][j] = len;
//     }

//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size(), m = nums2.size();
//         dp.assign(n, vector<int>(m, -1));

//         fun(n-1, m-1, nums1, nums2);
//         return ans;
//     }
// };