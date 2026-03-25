#include<bits/stdc++.h>
using namespace std;

// NEW PATTERN QUESTION - DP + BACKTRACKING 
// Checking optimally each time

class Solution {
public:
    map<vector<int>, int> dp;

    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(dp.count(needs)) return dp[needs];

        // Buy all items individually
        int cost = 0;
        for(int i = 0; i < needs.size(); i++) {
            cost += needs[i] * price[i];
        }

        // Try each special offer
        for(auto& offer : special) {
            vector<int> temp = needs;
            bool valid = true;

            for(int i = 0; i < needs.size(); i++) {
                if(temp[i] < offer[i]) {
                    valid = false;
                    break;
                }
                temp[i] -= offer[i];
            }

            if(valid) {
                cost = min(cost, offer.back() + solve(price, special, temp));
            }
        }

        return dp[needs] = cost;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price, special, needs);
    }
};