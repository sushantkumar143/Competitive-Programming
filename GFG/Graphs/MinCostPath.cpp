#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1?page=2&category=Graph&sortBy=submissions

class Solution {
public:
    int minimumCostPath(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int row[4] = {0,-1,0,1};
        int col[4] = {-1,0,1,0};

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        while(!pq.empty()) {

            auto [wt, corr] = pq.top();
            pq.pop();

            int r = corr.first;
            int c = corr.second;

            if(wt > dist[r][c]) continue;

            for(int k=0;k<4;k++) {

                int i = r + row[k];
                int j = c + col[k];

                if(i>=0 && j>=0 && i<n && j<m) {

                    if(dist[i][j] > dist[r][c] + grid[i][j]) {

                        dist[i][j] = dist[r][c] + grid[i][j];
                        pq.push({dist[i][j], {i,j}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
