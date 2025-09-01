#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> ops;
vector<vector<int>> g;
vector<int> vis;

void dfs(int u, int p = -1) {
    ops.push_back({1, u}); // check this node
    vis[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        ops.push_back({2, u}); // cut all edges of u before going to child
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        g.assign(n+1, {});
        for (int i=0;i<n-1;i++) {
            int u,v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vis.assign(n+1, 0);
        ops.clear();

        dfs(1); // root at 1

        cout << ops.size() << "\n";
        for (auto &op : ops) {
            cout << op.first << " " << op.second << "\n";
        }
    }
}
