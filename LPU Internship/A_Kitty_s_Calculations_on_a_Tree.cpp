#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

const int MAXN = 200005;
const int LOGN = 18; 

vector<int> adj[MAXN];

int depth[MAXN];
int parent[MAXN][LOGN];

/**
 * @brief 
 * @param u 
 * @param p
 * @param d 
 */




void dfs_lca(int u, int p, int d) {


    depth[u] = d;
    parent[u][0] = p;

    for (int i = 1; i < LOGN; i++) {
        if (parent[u][i - 1] != 0) {
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
        } else {
            parent[u][i] = 0;
        }
    }

    for (int v : adj[u]) {
        if (v != p) {
            dfs_lca(v, u, d + 1);
        }
    }


}



/**
 * @brief 
 * @param u
 * @param v 
 * @return 
 */



int get_lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }



    for (int i = LOGN - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }
    }



    if (u == v) {
        return u;
    }



    for (int i = LOGN - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }


    return parent[u][0];
}



/**
 * @brief 
 * @param u
 * @param v 
 * @return 
 */



int get_dist(int u, int v) {
    int lca = get_lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; 
    cin >> n >> q; 

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j < LOGN; ++j) {
            parent[i][j] = 0;
        }
    }

    dfs_lca(1, 0, 0);


    while (q--) { 
        int k;
        cin >> k;
        vector<int> query_set(k);
        for (int i = 0; i < k; i++) {
            cin >> query_set[i];
        }

        ll total_sum = 0;

        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                ll u = query_set[i];
                ll v = query_set[j];

                ll dist = get_dist(u, v);

                ll prod_uv = (u * v) % MOD;

                ll term = (prod_uv * dist) % MOD;

                total_sum = (total_sum + term) % MOD;
            }
        }

        cout << total_sum << "\n";
    }

}