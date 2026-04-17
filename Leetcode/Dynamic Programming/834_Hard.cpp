#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N;

    void DFS1(int node, int parent, vector<vector<int>>& adj, 
              vector<int>& count, vector<int>& res) {
        
        count[node] = 1;

        for(int child : adj[node]) {
            if(child == parent) continue;

            DFS1(child, node, adj, count, res);

            count[node] += count[child];
            res[node] += res[child] + count[child];
        }
    }

    void DFS2(int node, int parent, vector<vector<int>>& adj, 
              vector<int>& count, vector<int>& res) {
        
        for(int child : adj[node]) {
            if(child == parent) continue;

            res[child] = res[node] - count[child] + (N - count[child]);

            DFS2(child, node, adj, count, res);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        vector<vector<int>> adj(n);

        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> count(n, 0);
        vector<int> res(n, 0);

        DFS1(0, -1, adj, count, res);  
        DFS2(0, -1, adj, count, res);  

        return res;
    }
};