#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool solve(int idx, vector<int>& matchsticks, vector<int>& sides, int target) {
        if(idx == matchsticks.size()) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }

        for(int i = 0; i < 4; i++) {
            
            if(sides[i] + matchsticks[idx] > target) 
                continue;

            sides[i] += matchsticks[idx];

            if(solve(idx + 1, matchsticks, sides, target))
                return true;

            sides[i] -= matchsticks[idx];
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if(sum % 4 != 0) return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<int> sides(4, 0);

        return solve(0, matchsticks, sides, target);
    }
};