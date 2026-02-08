#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;

        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]) {
                    q.push({i, j});
                    grid[i][j] = 0;
                    vis[i][j] = 1;

                    while(!q.empty()) {
                        auto [i, j] = q.front();
                        q.pop();

                        int cnt = 4;
                        for(int k=0; k<4; k++) {
                            int r = i + row[k];
                            int c = j + col[k];

                            if(r>=0 && c>=0 && r<n && c<m) {
                                if(!vis[r][c] && grid[r][c]) {
                                    grid[r][c] = 0;
                                    vis[r][c] = 1;
                                    cnt--;
                                    q.push({r, c});
                                }
                                else if(vis[r][c]) cnt--;
                            }
                        }

                        perimeter += cnt;
                    }
                    break;
                }
            }
        }

        return perimeter;
    }
};