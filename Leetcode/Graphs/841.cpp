class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& rooms) {
        vis[node] = true;

        for(int neigh : rooms[node]) {
            if(!vis[neigh]) {
                dfs(neigh, vis, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);

        vis[0] = true;
        dfs(0, vis, rooms);

        for(bool v : vis) {
            if(!v) return false;
        }

        return true;
    }
};