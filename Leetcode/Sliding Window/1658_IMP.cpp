class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();

        int left = 0, sm = 0;
        int ans = -1;
        int n = nums.size();
        
        for(int right=0; right<n; right++) {
            sm += nums[right];
            while(sm > target) {
                sm -= nums[left++];
            }
            if(sm == target) {
                ans = max(ans, right-left+1);
            }
        }

        return ans==-1 ? -1 : n-ans;
    }
};