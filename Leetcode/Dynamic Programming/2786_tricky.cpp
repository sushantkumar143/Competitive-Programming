#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     long long maxScore(vector<int>& nums, int x) {

//         int n = nums.size();
//         vector<vector<long long>> dp(n, vector<long long>(2, LLONG_MIN));

//         dp[0][nums[0] % 2] = nums[0];

//         long long ans = nums[0];

//         for(int i = 1; i < n; i++) {
//             int p = nums[i] % 2;

//             for(int j = 0; j < i; j++) {
//                 for(int k = 0; k < 2; k++) {
//                     if(dp[j][k] == LLONG_MIN) continue;

//                     int penalty = (k == p) ? 0 : x;

//                     dp[i][p] = max(dp[i][p],
//                                    dp[j][k] + nums[i] - penalty);
//                 }
//             }

//             ans = max(ans, dp[i][p]);
//         }

//         return ans;
//     }
// };


// ERROR DUE TO INTEGER UNDERFLOW
// ---- this is only the core logic ----

// class Solution {
// public:
//     long long maxScore(vector<int>& nums, int x) {

//         long long even = LLONG_MIN, odd = LLONG_MIN;

//         if(nums[0] % 2 == 0) even = nums[0];
//         else odd = nums[0];

//         for(int i = 1; i < nums.size(); i++) {
//             if(nums[i] % 2 == 0) {
//                 even = max(even + nums[i], odd + nums[i] - x);
//             } 
//             else {
//                 odd = max(odd + nums[i], even + nums[i] - x);
//             }
//         }

//         return max(even, odd);
//     }
// };



class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {

        long long even = LLONG_MIN, odd = LLONG_MIN;

        if(nums[0] % 2 == 0) even = nums[0];
        else odd = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            long long ne = LLONG_MIN, no = LLONG_MIN;

            if(nums[i] % 2 == 0) {
                if(even != LLONG_MIN) ne = max(ne, even + nums[i]);
                if(odd  != LLONG_MIN) ne = max(ne, odd + nums[i] - x);
                even = ne;
            } 
            else {
                if(odd  != LLONG_MIN) no = max(no, odd + nums[i]);
                if(even != LLONG_MIN) no = max(no, even + nums[i] - x);
                odd = no;
            }
        }

        return max(even, odd);
    }
};
