class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);   // reversed graph
        vector<int> outDegree(n, 0);

        // build reverse graph + outdegree
        for(int i = 0; i < n; i++) {
            outDegree[i] = graph[i].size();
            for(int v : graph[i]) {
                adj[v].push_back(i);
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(outDegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int parent : adj[node]) {
                outDegree[parent]--;
                if(outDegree[parent] == 0)
                    q.push(parent);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
