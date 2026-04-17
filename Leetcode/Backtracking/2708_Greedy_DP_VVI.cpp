#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        vector<int> pos, neg;
        bool zero = false;

        for(int x : nums) {
            if(x > 0) pos.push_back(x);
            else if(x < 0) neg.push_back(x);
            else zero = true;
        }

        sort(neg.begin(), neg.end());

        // remove one negative if count is odd
        if(neg.size() % 2 == 1) {
            neg.pop_back();
        }

        long long res = 1;
        bool taken = false;

        for(int x : pos) {
            res *= x;
            taken = true;
        }

        for(int x : neg) {
            res *= x;
            taken = true;
        }

        if(!taken) {
            return zero ? 0 : *max_element(nums.begin(), nums.end());
        }

        return res;
    }
};



// BACKTRACKING

// class Solution {
// public:
//     long long ans = LLONG_MIN;

//     void dfs(int i, vector<int>& nums, long long prod, bool taken) {
//         if(i == nums.size()) {
//             if(taken)
//                 ans = max(ans, prod);
//             return;
//         }

//         // Take
//         dfs(i+1, nums, prod * nums[i], true);

//         // Not take
//         dfs(i+1, nums, prod, taken);
//     }

//     long long maxStrength(vector<int>& nums) {
//         dfs(0, nums, 1, false);
//         return ans;
//     }
// };
