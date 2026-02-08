#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!mat[i][j]) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(int k=0; k<4; k++) {
                int x = i + row[k];
                int y = j + col[k];

                if(x>=0 && y>=0 && x<n && y<m) {
                    if(dist[x][y] > dist[i][j]+1) {
                        dist[x][y] = 1 + dist[i][j];
                        q.push({x, y});
                    }
                }
            }
        }

        return dist;
    }
};