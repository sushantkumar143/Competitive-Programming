#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        int cost = 0;
        vector<int> mst(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            if(mst[node]) continue;
            mst[node] = 1;
            cost += dist;

            for(auto& neigh : adj[node]) {
                int no = neigh.first;
                int co = neigh.second;
                if(!mst[no]) {
                    pq.push({co, no});
                }
            }
        }

        return cost;
    }
};