#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int n;

int dfs(int u) {
    int depth = 1;
    for (int v : g[u]) {
        depth = max(depth, 1 + dfs(v));
    }
    return depth;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.assign(n + 1, {});
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        parent[i] = p;
        if (p != -1) {
            g[p].push_back(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) {
            ans = max(ans, dfs(i));
        }
    }

    cout << ans << "\n";
    return 0;
}
