#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int cnt = 1;
        int last = pairs[0][1];
        int n = pairs.size();
        for(int i=1; i<n; i++) {
            if(pairs[i][0] > last) {
                last = pairs[i][1];
                cnt++;
            }
        }

        return cnt;
    }
};