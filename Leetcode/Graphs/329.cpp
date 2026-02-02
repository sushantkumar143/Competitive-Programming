// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/?envType=problem-list-v2&envId=graph

class Solution {
public:
    int row[4] = {0, 0, 1, -1};
    int col[4] = {1, -1, 0, 0};

    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int m = matrix.size();
        int n = matrix[0].size();
        int best = 1;  // path length including this cell

        for (int k = 0; k < 4; k++) {
            int r = i + row[k];
            int c = j + col[k];

            if (r >= 0 && r < m && c >= 0 && c < n &&
                matrix[r][c] > matrix[i][j]) {
                best = max(best, 1 + dfs(r, c, matrix, dp));
            }
        }

        return dp[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j, matrix, dp));
            }
        }
        return ans;
    }
};
