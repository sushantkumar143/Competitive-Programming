class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto x : edges) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2] * 2});
        }

        const int INF = 1e9;                    // 1e9
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> q;

        vector<int> dist(n, INF);
        dist[0] = 0;
        q.push({0, 0});

        while (!q.empty()) {
            auto [wt, from] = q.top();
            q.pop();

            if (dist[from] < wt) continue;

            for (auto [to, cost] : adj[from]) {
                if (dist[to] > dist[from] + cost) {
                    dist[to] = dist[from] + cost;
                    q.push({dist[to], to});
                }
            }
        }

        return dist[n - 1] == INF ? -1 : dist[n - 1];
    }
};
