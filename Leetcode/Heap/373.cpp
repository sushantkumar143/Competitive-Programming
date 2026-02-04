#include<bits/stdc++.h>
using namespace std;

// VERY GOOD INTUTIVE QUESTION   --- MUST TRY ---

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<tuple<int, int, int>,
                        vector<tuple<int, int, int>>,
                        greater<>> pq;
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            pq.push({nums1[i]+nums2[0], i, 0});
        }

        while(k-- && !pq.empty()) {
            auto [sm, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            if(j+1 < m) {
                pq.push({nums1[i]+nums2[j+1], i, j+1});
            }
        }

        return ans;
    }
};