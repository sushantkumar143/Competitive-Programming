#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dpL(n, 1);
        vector<int> dpR(n, 1);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    dpL[i] = max(dpL[i], dpL[j]+1);
                }
            }
        }
        
        for(int i=n-1; i>=0; i--) {
            for(int j=n-1; j>i; j--) {
                if(nums[i] > nums[j]) {
                    dpR[i] = max(dpR[i], dpR[j]+1);
                }
            }
        }
        
        
        int maxi = 0;
        for(int i=0; i<n; i++) {
            if(dpL[i] > 1 && dpR[i] > 1) {  
                maxi = max(maxi, dpL[i] + dpR[i] - 1);
            }
        }
        
        return maxi;
    }
};
