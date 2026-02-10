#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1

class Solution {
  public:
    int minThrow(int N, int arr[]) {
        // code here
        vector<int> board(31);
        for(int i=1; i<=30; i++) board[i] = i;
        
        for(int i=0; i<N*2; i+=2) {
            board[arr[i]] = board[arr[i+1]];
        }
        
        vector<int> vis(31, 0);
        
        queue<pair<int, int>> q;
        q.push({1, 0});
        
        while(!q.empty()) {
            auto [node, move] = q.front();
            q.pop();
            
            if(node == 30) return move;
            
            for(int i=1; i<=6; i++) {
                int next = node+i;
                if(next <= 30) {
                    next = board[next];
                    if(!vis[next]) {
                        vis[next] = 1;
                        q.push({next, move+1});
                    }
                }
            }
        }
        
        return -1;
    }
};