#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sm = 0;
        long long n = nums.size();
        unordered_map<long long, long long> mp;
        for(int i=0; i<k; i++) {
            sm += nums[i];
            mp[nums[i]]++;
        }

        long long ans = 0;
        if(mp.size() == k) ans = max(ans, sm);

        for(int i=k; i<n; i++) {
            sm -= nums[i-k];
            mp[nums[i-k]]--;
            if(!mp[nums[i-k]]) mp.erase(nums[i-k]);

            sm += nums[i];
            mp[nums[i]]++;
            if(mp.size() == k) ans = max(ans, sm);
        }

        return ans;
    }
};