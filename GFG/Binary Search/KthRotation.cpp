#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        int n = arr.size();
        int ans = 0;
        int mn = INT_MAX;

        while (low <= high) {
            if (arr[low] <= arr[high]) {
                if (arr[low] < mn) {
                    mn = arr[low];
                    ans = low;
                }
                break;
            }

            int mid = low + (high - low) / 2;

            if (arr[low] <= arr[mid]) {
                if (arr[low] < mn) {
                    mn = arr[low];
                    ans = low;
                }
                low = mid + 1;
            }
            else {
                if (arr[mid] < mn) {
                    mn = arr[mid];
                    ans = mid;
                }
                high = mid - 1;
            }
        }
        return ans;
    }
};