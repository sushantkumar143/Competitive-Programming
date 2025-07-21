#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
vector<pair<int, int>> adj[MAXN];
int color[MAXN];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; ++i)
        {
            cin >> color[i];
            adj[i].clear();
        }
        long long totalCost = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].emplace_back(v, c);
            adj[v].emplace_back(u, c);
            if (color[u] != color[v])
                totalCost += c;
        }
        while (q--)
        {
            int v, newColor;
            cin >> v >> newColor;
            for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
            {
                int u = it->first;
                int c = it->second;
                if (color[u] != color[v])
                    totalCost -= c;
                if (color[u] != newColor)
                    totalCost += c;
            }
            color[v] = newColor;
            cout << totalCost << '\n';
        }
    }
}