#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int hasCat[MAXN];
bool visited[MAXN];
int n, m;
int valid = 0;

void dfs(int node, int parent, int cat) {
    visited[node] = true;

    if (hasCat[node]) cat++;
    else cat = 0;

    if (cat > m) return;

    bool isLeaf = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            isLeaf = false;
            dfs(neighbor, node, cat);
        }
    }

    if (isLeaf && node != 1) valid++;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> hasCat[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);

    cout << valid << endl;

    return 0;
}
