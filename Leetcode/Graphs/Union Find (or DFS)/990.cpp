#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& check, vector<vector<int>>& adj, int id) {
        check[node] = id;
        for(int i=0; i<adj[node].size(); i++) {
            if(check[adj[node][i]] == -1) {
                dfs(adj[node][i], check, adj, id);
            }
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> adj(26);
        int n = equations.size();

        for(string& s : equations) {
            if(s[1] == '=') {
                int from = s[0]-'a';
                int to = s[3]-'a';
                adj[to].push_back(from);
                adj[from].push_back(to);
            }
        }

        vector<int> check(26, -1);
        int id = 0;

        for(int i=0; i<26; i++) {
            if(check[i] == -1) {
                dfs(i, check, adj, id++);
            }
        }

        for(string& s : equations) {
            if(s[1] == '!') {
                if(check[s[0]-'a'] == check[s[3]-'a']) return false;
            }
        }

        return true;
    }
};