#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, long long> freq;
        long long pairs = 0, ans = 0;
        int n = nums.size();

        int l = 0;
        for (int r = 0; r < n; r++) {
            pairs += freq[nums[r]];
            freq[nums[r]]++;

            while (pairs >= k) {
                ans += (n - r);

                freq[nums[l]]--;
                pairs -= freq[nums[l]];
                l++;
            }
        }

        return ans;
    }
};