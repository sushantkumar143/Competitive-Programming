#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, -1);
        
        int window = 2 * k + 1;
        
        if(window > n) return res;
        
        long long sm = 0;
        
        for(int i = 0; i < window; i++) {
            sm += nums[i];
        }
        
        for(int i = k; i + k < n; i++) {
            res[i] = sm / window;
            
            sm -= nums[i - k];
            if(i + k + 1 < n) {
                sm += nums[i + k + 1];
            }
        }
        
        return res;
    }
};