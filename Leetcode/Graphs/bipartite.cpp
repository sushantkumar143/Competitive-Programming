class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        for(int neigh : graph[node]) {
            if(color[neigh] != -1) {
                if(color[neigh] == color[node]) 
                    return false;
            }
            else {
                color[neigh] = 1 - color[node];
                if(!dfs(neigh, graph, color)) 
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                color[i] = 0;
                if(!dfs(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};

/*
Why (1 - color[node]) is safe

If:
color[node] = 0 → 1 - 0 = 1
color[node] = 1 → 1 - 1 = 0
So the neighbor always gets the opposite color.
*/