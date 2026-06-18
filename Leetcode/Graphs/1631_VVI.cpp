#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        int row[4] = {0, -1, 0, 1};
        int col[4] = {-1, 0, 1, 0};

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int effort = curr[0];
            int i = curr[1];
            int j = curr[2];

            if(i == n-1 && j == m-1)
                return effort;

            for(int k=0; k<4; k++) {

                int ni = i + row[k];
                int nj = j + col[k];

                if(ni >= 0 && nj >= 0 && ni < n && nj < m) {

                    int newEffort =
                        max(effort, abs(heights[i][j] - heights[ni][nj]));

                    if(newEffort < dist[ni][nj]) {
                        dist[ni][nj] = newEffort;
                        pq.push({newEffort, ni, nj});
                    }
                }
            }
        }

        return 0;
    }
};



// TLE

// class Solution {
// public:

//     int res = INT_MAX;
//     int n, m;

//     int row[4] = {0, -1, 0, 1};
//     int col[4] = {-1, 0, 1, 0};

//     void dfs(int i, int j, int maxi,
//              vector<vector<int>>& heights,
//              vector<vector<bool>>& vis) {

//         if(i == n-1 && j == m-1) {
//             res = min(res, maxi);
//             return;
//         }

//         vis[i][j] = true;

//         for(int k=0; k<4; k++) {

//             int ni = i + row[k];
//             int nj = j + col[k];

//             if(ni >= 0 && nj >= 0 &&
//                ni < n && nj < m &&
//                !vis[ni][nj]) {

//                 int newMaxi =
//                     max(maxi,
//                     abs(heights[i][j] - heights[ni][nj]));

//                 dfs(ni, nj, newMaxi, heights, vis);
//             }
//         }

//         vis[i][j] = false;
//     }

//     int minimumEffortPath(vector<vector<int>>& heights) {

//         n = heights.size();
//         m = heights[0].size();

//         vector<vector<bool>> vis(n,
//             vector<bool>(m, false));

//         dfs(0, 0, 0, heights, vis);

//         return res;
//     }
// };