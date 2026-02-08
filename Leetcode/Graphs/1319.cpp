#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;

        for(auto neigh : adj[node]) {
            if(!vis[neigh]) {
                dfs(neigh, vis, adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for(int i=0; i<connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }


        int notConnected = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj);
                 notConnected++;
            }
        }

        return notConnected-1;
    }
};