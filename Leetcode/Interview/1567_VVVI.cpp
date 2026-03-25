#include<bits/stdc++.h>
using namespace std;


// ALSO TRY THE QUESTION : FIND MAXIMUM PRODUCT FROM ANY SUBARRAY OF AN ARRAY  --- VVI 
// use this question use prefix product and suffix product then compute maximum at every step
// int prod = 1;
// int n = nums.size();
// int ans = INT_MIN;

// for(int i=0; i<n; i++) {
//     if(nums[i] == 0) prod = 1;
//     else prod *= nums[i];
//     ans = max(ans, prod);
// }
// for(int i=n-1; i>=0; i--) {
//     if(nums[i] == 0) prod = 1;
//     else prod *= nums[i];
//     ans = max(ans, prod);
// }
// return ans;




class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        // pos → length of subarray with positive product
        // neg → length of subarray with negative product
        
        int pos = 0;
        int neg = 0;
        int ans = 0;

        for(int& x : nums) {
            if(x > 0) {
                pos = pos + 1;
                neg = (neg > 0) ? neg+1 : 0;
            }
            else if(x < 0) {
                int temp = pos;
                pos = (neg > 0) ? neg+1 : 0;
                neg = temp+1;
            }
            else {  // x == 0  (reset both)
                pos = 0;
                neg = 0;
            }

            ans = max(pos, ans);
        }

        return ans;
    }
};