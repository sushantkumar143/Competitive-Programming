#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> st;
        int cnt = 0;
        int sm = 0;
        st.insert(0);

        for(int& x : nums) {
            sm += x;
            if(st.count(sm - target)) {
                cnt++;
                sm = 0;
                st.clear();
                st.insert(0);
            }
            st.insert(sm);
        }

        return cnt;
    }
};