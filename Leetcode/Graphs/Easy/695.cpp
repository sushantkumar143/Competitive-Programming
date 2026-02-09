#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n,m;
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    int dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 0;
        int cnt = 1;

        for(int k=0; k<4; k++) {
            int r = i + row[k];
            int c = j + col[k];

            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]) {
                grid[r][c] = 0;
                cnt = cnt + dfs(r, c, grid);
            }
        }

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int area = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]) {
                    area = max(area, dfs(i, j, grid));
                }
            }
        }

        return area;
    }
};