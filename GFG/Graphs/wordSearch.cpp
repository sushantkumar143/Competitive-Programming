#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/word-search/1?page=2&category=Graph&sortBy=submissions

class Solution {
  public:
    int n,m;
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};
    
    bool fun(int i, int j, int idx, vector<vector<char>> &mat, string &word, vector<vector<int>>& vis) {
        if(idx == word.size()) return true;
        
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || mat[i][j] != word[idx]) return false;
        
        vis[i][j] = 1;
        for(int k=0; k<4; k++) {
            int nr = i + row[k];
            int nc = j + col[k];
            
            if(fun(nr, nc, idx+1, mat, word, vis)) return true;
        }
        vis[i][j] = 0;
        
        return false;
    }
  
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        n = mat.size();
        m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(fun(i, j, 0, mat, word, vis)) return true;
            }
        }
        
        return false;
    }
};