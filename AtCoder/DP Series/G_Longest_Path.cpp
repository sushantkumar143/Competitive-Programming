#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>>& adj, vector<int>& dp) {
    if(dp[node] != -1) return dp[node];
    int cnt = 0;

    for(int i=0; i<adj[node].size(); i++) {
        int neigh = adj[node][i];
        cnt = max(cnt, 1 + dfs(neigh, adj, dp));
    }

    return dp[node] = cnt;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n);
    int x = n;
    while(e--) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
    }

    int maxi = 0;
    vector<int> dp(n, -1);

    for(int i=0; i<n; i++) {
        maxi = max(maxi, dfs(i, adj, dp));
    }

    cout << maxi;

}