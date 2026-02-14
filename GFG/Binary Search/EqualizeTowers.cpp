#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1

class Solution {
  public:
    long long computeCost(vector<int>& heights, vector<int>& cost, int H) {
        long long total = 0;
        for (int i = 0; i < heights.size(); i++) {
            total += 1LL * abs(heights[i] - H) * cost[i];
        }
        return total;
    }

    int minCost(vector<int>& heights, vector<int>& cost) {
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());

        long long ans = LLONG_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long costMid = computeCost(heights, cost, mid);
            long long costMidPlus = computeCost(heights, cost, mid + 1);

            ans = min(ans, costMid);

            if (costMidPlus < costMid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }
};