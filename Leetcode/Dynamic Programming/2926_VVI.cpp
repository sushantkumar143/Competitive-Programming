#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;
        map<int, long long> mp;

        for(int i=0; i<n; i++) {
            long long sm = nums[i];
            auto it = mp.upper_bound(nums[i]-i);
            
            if(it != mp.begin()) {
                it--;
                sm += it->second;
            }

            mp[nums[i]-i] = max(mp[nums[i]-i], sm);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && it->second <= sm) {
                mp.erase(it++);
            }

            ans = max(ans, sm);
        }

        return ans;
    }
};




// class Solution {
// public:
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int n = nums.size();

//         vector<long long> dp(n);
//         for(int i = 0; i < n; i++)
//             dp[i] = nums[i];

//         long long maxi = nums[0];

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < i; j++) {
//                 if(nums[i]-i >= nums[j]-j) {                     
//                     dp[i] = max(dp[i], dp[j] + nums[i]);   
//                 }
//             }
//             maxi = max(maxi, dp[i]);
//         }

//         return maxi;
//     }
// };