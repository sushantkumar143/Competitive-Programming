#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1?page=1&category=Recursion,Backtracking&sortBy=submissions

class Solution {
  public:
    
    bool check(int node, int c, vector<vector<int>>& adj, vector<int>& color) {
        for(int neigh : adj[node]) {
            if(color[neigh] == c) return false;
        }
        return true;
    }
  
    bool solve(int node, int v, vector<vector<int>>& adj, int m, vector<int>& color) {
        if(node == v) return true; 
        
        for(int c = 1; c <= m; c++) {
            if(check(node, c, adj, color)) {
                color[node] = c;
                
                if(solve(node + 1, v, adj, m, color))
                    return true;
                
                color[node] = 0;
            }
        }
        return false;
    }
  
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);
        
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> color(v, 0);
        return solve(0, v, adj, m, color);
    }
};