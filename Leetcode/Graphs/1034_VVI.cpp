#include<bits/stdc++.h>
using namespace std;

// COLORING THE BORDER

/*
1. Store the original color
2. BFS through connected component
3. For each cell: It’s a border if - on grid edge OR any neighbor has different color
4. Collect border cells
5. Color them at the end
*/

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        int orig = grid[row][col];

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<pair<int,int>> border;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        q.push({row, col});
        vis[row][col] = 1;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            bool isBorder = false;

            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m)
                    isBorder = true;
                else if(grid[nr][nc] != orig)
                    isBorder = true;
                else if(!vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }

            if(isBorder)
                border.push_back({r, c});
        }

        for(auto &p : border)
            grid[p.first][p.second] = color;

        return grid;
    }
};