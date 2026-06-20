#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int dfs(int idx, int n, vector<vector<pair<int, int>>>& adj, vector<int>& dist, vector<int>& dp) {
        if(idx == n) return 1;
        if(dp[idx] != -1) return dp[idx];

        int cnt = 0;
        for(auto& [node, wt] : adj[idx]) {
            if(dist[node] < dist[idx]) {
                cnt = (cnt + dfs(node, n, adj, dist, dp)) % MOD;
            }
        }

        return dp[idx] = cnt;
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, n});
        dist[n] = 0;

        while(!q.empty()) {
            auto [wt, node] = q.top();
            q.pop();

            if(wt > dist[node]) continue;

            for(auto neigh : adj[node]) {
                if(dist[neigh.first] > wt + neigh.second) {
                    dist[neigh.first] = wt + neigh.second;
                    q.push({dist[neigh.first], neigh.first});
                }
            }
        }

        vector<int> dp(n+1, -1);
        return dfs(1, n, adj, dist, dp);
    }
};