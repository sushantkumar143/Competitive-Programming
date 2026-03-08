#include<bits/stdc++.h>
using namespace std;

// Find all the connected components and count them. The answer is total number of stones - number of connected components. Because in each connected component we can remove all the stones except one. So we need to find the number of connected components and subtract it from total number of stones to get the answer.

class Solution {
public:
    int n;
    void dfs(int node, vector<int>& vis, vector<vector<int>>& stones) {
        vis[node] = 1;
        for(int i=0; i<n; i++) {
            if(!vis[i] && (stones[i][0] == stones[node][0] || stones[i][1]==stones[node][1])) {
                dfs(i, vis, stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<int> vis(n, 0);
        int connected = 0;
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, vis, stones);
                connected++;
            }
        }

        return n - connected;
    }
};