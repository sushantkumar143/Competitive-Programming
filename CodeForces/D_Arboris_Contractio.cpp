#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> adj[200005];
int dp[200005];
int ans[200005];
int degree[200005];
int n;

void dfs1(int u, int p) {
    dp[u] = 0;
    bool is_leaf = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        is_leaf = false;
        dfs1(v, u);
        dp[u] += dp[v];
    }
    if (is_leaf) {
        dp[u] = 1;
    }
}

void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        int up_leaves = ans[u] - dp[v];
        if (up_leaves == 0) {
            up_leaves = 1;
        }
        ans[v] = dp[v] + up_leaves;
        dfs2(v, u);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        degree[i] = 0;
    }
    bool is_star = false;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    if (n <= 2) {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (degree[i] == n - 1) {
            is_star = true;
            break;
        }
    }

    if (is_star) {
        cout << 0 << endl;
        return;
    }

    dfs1(1, 0);
    ans[1] = dp[1];
    dfs2(1, 0);

    int min_ops = n;
    for (int i = 1; i <= n; ++i) {
        min_ops = min(min_ops, ans[i]);
    }
    
    cout << min_ops - 1 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}