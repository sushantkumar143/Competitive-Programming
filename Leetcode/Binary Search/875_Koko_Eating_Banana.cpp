#include<bits/stdc++.h>
using namespace std;

// SIMILAR QUESTION:
// 2064, 2178, 2226

class Solution {
public:
    bool check(int speed, vector<int>& piles, int h) {
        long long sm = 0;
        for(int p : piles) {
            sm += (p + speed - 1) / speed; 
        }
        return sm <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(check(mid, piles, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};