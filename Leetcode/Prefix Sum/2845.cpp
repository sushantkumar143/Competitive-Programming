#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        long long prefix = 0;
        unordered_map<long long, long long> mp;
        mp[0] = 1;

        for(int x : nums) {
            if(x % modulo == k) prefix++;

            long long cur = prefix % modulo;
            long long need = (cur - k + modulo) % modulo;

            if(mp.count(need)) {
                ans += mp[need];
            }

            mp[cur]++;
        }

        return ans;
    }
};