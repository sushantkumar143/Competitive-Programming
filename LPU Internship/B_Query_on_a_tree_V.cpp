#include <bits/stdc++.h>
using namespace std;

const int N = 100005, INF = 1e9;
vector<int> g[N];
int sz[N], par[N], dep[N], d[N][20];
bool rem[N], col[N];
multiset<int> s[N];

int dfs1(int u, int p) {
    sz[u] = 1;
    for (int v : g[u])
        if (v != p && !rem[v])
            sz[u] += dfs1(v, u);
    return sz[u];
}

int cen(int u, int p, int tot) {
    for (int v : g[u])
        if (v != p && !rem[v] && sz[v] > tot / 2)
            return cen(v, u, tot);
    return u;
}

void dfs2(int u, int p, int l, int dis) {
    d[u][l] = dis;
    for (int v : g[u])
        if (v != p && !rem[v])
            dfs2(v, u, l, dis + 1);
}

void decomp(int u, int p, int l) {
    int tot = dfs1(u, p);
    int c = cen(u, p, tot);
    par[c] = (p == -1 ? c : p);
    dep[c] = l;
    dfs2(c, -1, l, 0);
    rem[c] = 1;
    for (int v : g[c])
        if (!rem[v])
            decomp(v, c, l + 1);
}

void upd(int u) {
    col[u] ^= 1;
    int x = u;
    while (1) {
        int l = dep[x];
        if (col[u]) s[x].insert(d[u][l]);
        else s[x].erase(s[x].find(d[u][l]));
        if (x == par[x]) break;
        x = par[x];
    }
}

int qry(int u) {
    int ans = INF, x = u;
    while (1) {
        int l = dep[x];
        if (!s[x].empty()) ans = min(ans, d[u][l] + *s[x].begin());
        if (x == par[x]) break;
        x = par[x];
    }
    return ans == INF ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n;
    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    decomp(1, -1, 0);
    cin >> q;
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 0) upd(x);
        else cout << qry(x) << "\n";
    }
}
