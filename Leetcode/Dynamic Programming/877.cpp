#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int fun(int i, int j, vector<int>& piles) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int takeLeft  = piles[i] - fun(i + 1, j, piles);
        int takeRight = piles[j] - fun(i, j - 1, piles);

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));

        return fun(0, n - 1, piles) > 0;
    }
};



// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         return true;
//     }
// };