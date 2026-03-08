#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& color, vector<vector<int>>& adj) {
        bool used[5] = {false};

        for(int neigh : adj[node]) {
            if(color[neigh] != -1)
                used[color[neigh]] = true;
        }

        for(int c = 1; c <= 4; c++) {
            if(!used[c]) {
                color[node] = c;
                break;
            }
        }

        for(int neigh : adj[node]) {
            if(color[neigh] == -1) {
                dfs(neigh, color, adj);
            }
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);

        for(auto &p : paths){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        vector<int> color(n+1, -1);

        for(int i = 1; i <= n; i++){
            if(color[i] == -1){
                dfs(i, color, adj);
            }
        }

        color.erase(color.begin());
        return color;
    }
};