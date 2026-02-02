class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(target == nums[mid]) return true;
            else if(nums[mid] == nums[low] && nums[mid] == nums[high]) {
                high--;
                low++;
            }
            else if(nums[mid] >= nums[low]) {
                if(nums[low] <= target && target < nums[mid]) {
                    high = mid-1;
                }
                else low = mid+1;
            }
            else {
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid+1;
                }
                else high = mid-1;
            }
        }
        return false;
    }
};