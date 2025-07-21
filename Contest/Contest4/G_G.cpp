#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    // Topological sort using Kahn's algorithm
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    vector<int> dp(n + 1, -INF);
    vector<int> parent(n + 1, -1);
    dp[1] = 1; // path from 1 to 1 includes 1 city

    for (int u : topo) {
        for (int v : graph[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (dp[n] < 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dp[n] << "\n";
        vector<int> path;
        int curr = n;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        for (int x : path) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
