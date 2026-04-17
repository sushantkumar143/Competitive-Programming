#include<bits/stdc++.h>
using namespace std;

// RETURN A FREQENCY ARRAY OF SIZE 26 TO PARENT 

// This code is giving MLE

class Solution {
public:
    vector<int> dfs(int node, int prev, vector<vector<int>>& adj, string labels, vector<int>& res) {
        int cnt = 1;
        vector<int> freq(26, 0);

        for(int neigh : adj[node]) {
            if(prev == neigh) continue;

            vector<int> childFreq = dfs(neigh, node, adj, labels, res);

            for(int i=0; i<26; i++) {
                freq[i] += childFreq[i];
            }
        }
        freq[labels[node]-'a']++;
        res[node] = freq[labels[node]-'a'];
        return freq;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n);
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, adj, labels, res);

        return res;
    }
};



// SPACE OPTIMIZD CODE

class Solution {
public:
    vector<vector<int>> count;

    void dfs(int node, int parent, vector<vector<int>>& adj, string& labels, vector<int>& res) {
        count[node][labels[node] - 'a'] = 1;

        for(int neigh : adj[node]) {
            if(neigh == parent) continue;

            dfs(neigh, node, adj, labels, res);

            // Merge child into current
            for(int i = 0; i < 26; i++) {
                count[node][i] += count[neigh][i];
            }
        }

        res[node] = count[node][labels[node] - 'a'];
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        vector<int> res(n);

        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        count.resize(n, vector<int>(26, 0));

        dfs(0, -1, adj, labels, res);

        return res;
    }
};