class Solution {
public:
    int fun(vector<int>& arr, int target, int mid) {
        int sm = 0;
        for(int i : arr) {
            sm += min(i, mid);
        }
        return sm;
    }

    int findBestValue(vector<int>& arr, int target) {
        int low = 0;
        int high = *max_element(arr.begin(), arr.end());
        int ans = INT_MAX;
        int temp = 0;

        while(low <= high) {
            int mid = low + (high-low)/2;
            int sm = fun(arr, target, mid);
            int diff = abs(sm - target);

            if(ans > diff || (diff == ans && mid < temp)) {
                ans = diff;
                temp = mid;
            }

            if(sm < target) {
                low = mid+1;
            }
            else high = mid-1;
        }

        return temp;
    }
};