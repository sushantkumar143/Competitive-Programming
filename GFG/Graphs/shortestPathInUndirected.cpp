#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?page=2&category=Graph&sortBy=submissions

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> dist(n+1, 1e9), parent(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;
        vector<vector<pair<int, int>>> adj(n+1);
        
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 1});
        dist[1] = 0;
        
        while(!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();
            
            if(dist[node] < wt) continue;
            
            for(auto& [neigh, w] : adj[node]) {
                if(dist[neigh] > dist[node] + w) {
                    dist[neigh] = dist[node]+w;
                    pq.push({dist[neigh], neigh});
                    parent[neigh] = node;
                }
            }
        }
        
        if (dist[n] == 1e9) return {-1};
        
        vector<int> path;
        int node = n;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[n]);

        return path;
    }
};