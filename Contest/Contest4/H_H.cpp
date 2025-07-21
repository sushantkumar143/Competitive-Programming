#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    
    // Input graph
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    // Min-heap: {cost, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);

    // Store top k shortest distances for each node
    vector<vector<int>> dist(n + 1);

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();

        if (dist[u].size() >= k) continue;
        dist[u].push_back(cost);

        for (auto &[v, w] : adj[u]) {
            if (dist[v].size() < k) {
                pq.emplace(cost + w, v);
            }
        }
    }

    // Output k shortest distances to node n
    for (int i = 0; i < k; ++i) {
        cout << dist[n][i] << " ";
    }
    cout << "\n";

    return 0;
}
