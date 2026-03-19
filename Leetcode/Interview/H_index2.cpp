#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        // for(int i=0; i<n; i++) {
        //     int h = n-i;
        //     if(citations[i] >= h) return h;
        // }

        int left = 0;
        int right = n-1;

        while(left <= right) {
            int mid = left + (right-left)/2;
            int h = n-mid;

            if(citations[mid] >= n-mid) {
                right = mid-1;
            }
            else left = mid+1;
        }

        return n-left;
    }
};