#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int node, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[node] = true;
        int cnt = 1; 

        for(auto& neigh : adj[node]) {
            if(!vis[neigh]) {
                cnt += dfs(neigh, vis, adj);
            }
        }

        return cnt;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> connected;
        vector<bool> vis(n ,false);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                connected.push_back(dfs(i, vis, adj));
            }
        }

        long long sm = accumulate(connected.begin(), connected.end(), 0);
        for(int i=0; i<connected.size(); i++) {
            long long t = sm - connected[i];
            ans += (long long)(t * connected[i]);
            sm -= connected[i];
        }

        return ans;
    }
};