#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/word-boggle4143/1?page=2&category=Graph&sortBy=submissions

class Solution {
  public:
    int n,m, maxi;
    int row[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int col[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    void fun(int i, int j, string& temp, vector<vector<char>>& board,
         vector<vector<int>>& vis, unordered_set<string>& dict,
         unordered_set<string>& ans) {

        vis[i][j] = 1;
        temp.push_back(board[i][j]);
    
        if(temp.size() > maxi) {
            temp.pop_back();
            vis[i][j] = 0;
            return;
        }
    
        if(dict.count(temp)) ans.insert(temp);
    
        for(int k=0; k<8; k++) {
            int nr = i + row[k];
            int nc = j + col[k];
    
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc])
                fun(nr, nc, temp, board, vis, dict, ans);
        }
    
        temp.pop_back();
        vis[i][j] = 0;
    }

    
    vector<string> wordBoggle(vector<vector<char> >& board,
                              vector<string>& dictionary) {
        // Code here 
        n = board.size();
        m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        unordered_set<string> ans;
        string s = "";
        maxi = 0;
        for(string& i : dictionary) {
            int p = i.length();
            maxi = max(maxi, p);
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                fun(i, j, s, board, vis, dict, ans);
            }
        }
        
        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};