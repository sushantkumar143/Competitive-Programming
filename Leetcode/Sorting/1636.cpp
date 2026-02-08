#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;

        vector<pair<int, int>> arr;
        for (auto& [num, f] : freq)
            arr.push_back({f, num});

        sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
            if (a.first != b.first)
                return a.first < b.first;  
            return a.second > b.second;  
        });

        vector<int> ans;
        for (auto& [f, num] : arr) {
            while (f--)
                ans.push_back(num);
        }

        return ans;
    }
};