#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int i, vector<int>& arr, vector<bool>& vis) {
        if (i < 0 || i >= arr.size() || vis[i]) return false;
        if (arr[i] == 0) return true;

        vis[i] = true;

        return dfs(i + arr[i], arr, vis) ||
               dfs(i - arr[i], arr, vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        return dfs(start, arr, vis);
    }
};