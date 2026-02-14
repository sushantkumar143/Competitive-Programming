// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/circle-of-strings4530/1?page=2&category=Graph&sortBy=submissions

class Solution {
  public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        
        for(auto& neigh : adj[node]) {
            if(!vis[neigh]) dfs(neigh, vis, adj);
        }
    }
  
    int isCircle(vector<string> &arr) {
        // code here
        vector<int> present(26, 0);
        vector<vector<int>> adj(26);
        int n = arr.size();
        
        for(string& s : arr) {
            int from = s[0]-'a';
            int to = s[s.length()-1]-'a';
            
            adj[from].push_back(to);
            present[from] = 1;
            present[to] = 1;
        }
        
        vector<int> indegree(26, 0);
        vector<int> outdegree(26, 0);
        
        for(int i=0; i<adj.size(); i++) {
            for(auto& neigh : adj[i]){
                indegree[neigh]++;
            }
            outdegree[i] = adj[i].size();
        }
        
        for(int i=0; i<26; i++) {
            if(indegree[i] != outdegree[i]) return false;
        }
        
        for(int i=0; i<26; i++) {
            if(present[i]) {
                vector<int> vis(26, 0);
                dfs(i, vis, adj);
                
                bool flag = true;
                for(int i=0; i<26; i++) {
                    if(present[i] && !vis[i]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) return true;
            }
        }
        
        return false;
    }
};