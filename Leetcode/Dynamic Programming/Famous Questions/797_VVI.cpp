#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    void dfs(int node, vector<int>& temp, vector<vector<int>> adj, vector<int>& vis, vector<vector<int>>& res) {
        
        vis[node] = 1;
        temp.push_back(node);

        if(node == n-1) {
            res.push_back(temp);
            // return;
        }

        for(int& neigh : adj[node]) {
            if(!vis[neigh]) {
                dfs(neigh, temp, adj,vis, res);
            }
        }

        vis[node] = 0;
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(int e : graph[i]) {
                adj[i].push_back(e);
            }
        }

        vector<vector<int>> res;
        vector<int> vis(n, 0);
        vector<int> temp;
        dfs(0, temp, adj, vis, res);
        return res;
    }
};