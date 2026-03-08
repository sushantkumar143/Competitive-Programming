#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n = edges.size();  // Fix 1: edges = n-1, nodes = n+1
        vector<vector<int>> adj(n + 2);  

        for(int i = 0; i < n; i++) {
            int from = edges[i][0];  
            int to   = edges[i][1];

            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        for(int i = 1; i <= n + 1; i++) {
            if(adj[i].size() == n) { 
                return i;
            }
        }

        return -1;
    }
};