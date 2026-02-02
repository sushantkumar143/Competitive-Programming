class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &t : times) {
            adj[t[0]-1].push_back({t[1]-1, t[2]});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k-1] = 0;
        pq.push({0, k-1});

        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto edge : adj[node]) {
                int neigh = edge.first;
                int weight = edge.second;

                if(dist[neigh] > dist[node] + weight) {
                    dist[neigh] = dist[node] + weight;
                    pq.push({weight, neigh});
                }
            }
        }

        int ans = INT_MIN;
        for(int d : dist) {
            if(d == INT_MAX) return -1;
            ans = max(ans, d);
        }

        return ans;
    }
};