#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 100005;
const int LOGN = 18;

// --- Tree and LCA ---
vector<int> adj[MAXN];
int weights[MAXN];
int depth[MAXN];
int parent[MAXN][LOGN]; // For binary lifting

// --- Coordinate Compression ---
int compressed_weights[MAXN];    // Node i's weight, compressed
vector<int> index_to_weight; // Maps compressed index back to original
map<int, int> weight_to_index; // Maps original weight to compressed

// --- Persistent Segment Tree (PST) ---
struct Node {
    Node *left, *right;
    int count;

    Node(int c, Node* l, Node* r) : count(c), left(l), right(r) {}
    
    // Update function for the PST
    Node* update(int idx, int val, int l, int r);
};

// A "null" node for empty leaves
Node* null_node = new Node(0, nullptr, nullptr);
Node* roots[MAXN]; // roots[i] = PST for path from root to node i

Node* Node::update(int idx, int val, int l, int r) {
    if (l == r) {
        return new Node(this->count + val, null_node, null_node);
    }
    
    int mid = l + (r - l) / 2;
    Node* new_left = this->left;
    Node* new_right = this->right;

    if (idx <= mid) {
        new_left = this->left->update(idx, val, l, mid);
    } else {
        new_right = this->right->update(idx, val, mid + 1, r);
    }
    
    return new Node(new_left->count + new_right->count, new_left, new_right);
}

// DFS to compute depth and parent[u][0]
void dfs_lca(int u, int p, int d) {
    depth[u] = d;
    parent[u][0] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_lca(v, u, d + 1);
        }
    }
}

// DFS to build the Persistent Segment Tree
void dfs_pst(int u, int p) {
    // roots[u] = roots[p] + weight[u]
    roots[u] = roots[p]->update(compressed_weights[u], 1, 0, index_to_weight.size() - 1);
    for (int v : adj[u]) {
        if (v != p) {
            dfs_pst(v, u);
        }
    }
}

// Build the binary lifting table
void build_binary_lifting(int n) {
    for (int i = 1; i < LOGN; i++) {
        for (int u = 1; u <= n; u++) {
            if (parent[u][i - 1] != 0) {
                parent[u][i] = parent[parent[u][i - 1]][i - 1];
            } else {
                parent[u][i] = 0;
            }
        }
    }
}

// Get LCA in O(log N)
int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = LOGN - 1; i >= 0; i--) {
        if (parent[u][i] != 0 && depth[parent[u][i]] >= depth[v]) {
            u = parent[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOGN - 1; i >= 0; i--) {
        if (parent[u][i] != 0 && parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int query_pst(Node* u, Node* v, Node* lca, Node* p_lca, int l, int r, int k) {
    if (l == r) {
        return l;
    }

    int left_count = u->left->count + v->left->count - lca->left->count - p_lca->left->count;
    
    int mid = l + (r - l) / 2;
    if (k <= left_count) {
        return query_pst(u->left, v->left, lca->left, p_lca->left, l, mid, k);
    } else {
        return query_pst(u->right, v->right, lca->right, p_lca->right, mid + 1, r, k - left_count);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> sorted_weights(n);
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
        sorted_weights[i - 1] = weights[i];
    }

    // --- 1. Coordinate Compression ---
    sort(sorted_weights.begin(), sorted_weights.end());
    sorted_weights.erase(unique(sorted_weights.begin(), sorted_weights.end()), sorted_weights.end());

    for (int i = 0; i < sorted_weights.size(); i++) {
        weight_to_index[sorted_weights[i]] = i;
        index_to_weight.push_back(sorted_weights[i]);
    }
    for (int i = 1; i <= n; i++) {
        compressed_weights[i] = weight_to_index[weights[i]];
    }
    int compressed_max_idx = index_to_weight.size() - 1;

    // --- 2. Read Tree & Build LCA ---
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize the "null" node's pointers to itself
    null_node->left = null_node;
    null_node->right = null_node;
    roots[0] = null_node; // root 0 is the empty tree

    dfs_lca(1, 0, 0);
    build_binary_lifting(n);

    // --- 3. Build PST ---
    dfs_pst(1, 0);

    // --- 4. Process Queries ---
    for (int i = 0; i < m; i++) {
        int u, v, k;
        cin >> u >> v >> k;

        int lca = get_lca(u, v);
        int p_lca = parent[lca][0];

        int compressed_idx = query_pst(roots[u], roots[v], roots[lca], roots[p_lca], 0, compressed_max_idx, k);
        
        cout << index_to_weight[compressed_idx] << "\n";
    }

    return 0;
}