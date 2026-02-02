#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;

int n;
vector<vector<int>> adj;
vector<int> A;
vector<int> depth;
vector<vector<int>> nodes_by_value;

ll part2_sum = 0;


void dfs_depths(int u, int p, int d) {
    depth[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_depths(v, u, d + 1);
        }
    }
}


map<int, int> dfs_lca_sum(int u, int p) {
    map<int, int> counts_in_subtree;
    map<int, int> counts_from_children;

    ll A_pairs_lca_u = 0;

    for (int v : adj[u]) {
        if (v == p) continue;

        map<int, int> child_counts = dfs_lca_sum(v, u);

        for (auto const& [val, count] : child_counts) {
            if (counts_from_children.count(val)) {
                A_pairs_lca_u += (ll)count * counts_from_children[val];
            }
        }
        
        for (auto const& [val, count] : child_counts) {
            counts_from_children[val] += count;
        }

        if (counts_in_subtree.size() < child_counts.size()) {
            swap(counts_in_subtree, child_counts);
        }
        for (auto const& [val, count] : child_counts) {
            counts_in_subtree[val] += count;
        }
    }

    int v_self = A[u];
    if (counts_from_children.count(v_self)) {
        A_pairs_lca_u += counts_from_children[v_self];
    }
    
    part2_sum += (ll)depth[u] * A_pairs_lca_u * -2;

    counts_in_subtree[v_self]++;
    
    return counts_in_subtree;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    adj.resize(n + 1);
    A.resize(n + 1);
    depth.resize(n + 1);
    nodes_by_value.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        nodes_by_value[A[i]].push_back(i);
    }

    dfs_depths(1, 0, 0);

    ll part1_sum = 0;
    for (int v = 1; v <= n; v++) {
        if (nodes_by_value[v].size() < 2) {
            continue;
        }
        ll k = nodes_by_value[v].size();
        ll sum_depth = 0;
        for (int node : nodes_by_value[v]) {
            sum_depth += depth[node];
        }
        part1_sum += (k - 1) * sum_depth;
    }

    dfs_lca_sum(1, 0);

    cout << part1_sum + part2_sum << "\n";

    return 0;
}