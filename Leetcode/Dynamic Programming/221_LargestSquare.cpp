#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int side = 0;

        // HERE DP[i][j] STATES THE SIDE OF A SQUARE

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') {
                    if(!i || !j) dp[i][j] = 1;
                    else{ 
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                    side = max(side, dp[i][j]);
                }
            }
        }

        return side*side;
    }
};