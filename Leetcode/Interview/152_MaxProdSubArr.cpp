#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProduct = nums[0];
        int minProduct = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            if(x < 0) swap(maxProduct, minProduct);

            maxProduct = max(x, maxProduct * x);
            minProduct = min(x, minProduct * x);

            ans = max(ans, maxProduct);
        }

        return ans;
    }
};