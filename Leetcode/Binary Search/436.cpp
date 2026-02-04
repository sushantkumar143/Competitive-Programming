#include<bits/stdc++.h>
using namespace std;

// VERY GOOD INTUTIVE QUESTION   --- MUST TRY ---

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> start;
        for(int i=0; i<n; i++) {
            start.push_back({intervals[i][0], i});
        }

        sort(start.begin(), start.end());

        vector<int> ans(n);
        for(int i=0 ;i<n; i++) {
            int end = intervals[i][1];

            int low = 0;
            int high = n-1;
            int pos = -1;
            while(low <= high) {
                int mid = low + (high-low)/2;

                if(start[mid].first >= end) {
                    pos = start[mid].second;
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }

            ans[i] = pos;
        }

        return ans;
    }
};