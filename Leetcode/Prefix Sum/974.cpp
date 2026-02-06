#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt = 0;
        int sm = 0;
        mp[0] = 1;

        for(int& i : nums) {
            sm += i;
            int mod = ((sm % k) + k) % k;   // Handle Negative Cases
            cnt += mp[mod];
            mp[mod]++;
        }

        return cnt;
    }
};