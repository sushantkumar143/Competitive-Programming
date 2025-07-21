#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<vector<int>> rev_graph(n);
    for (int i = 0; i < n; ++i) {
        if (i - a[i] >= 0)
            rev_graph[i - a[i]].push_back(i);
        if (i + a[i] < n)
            rev_graph[i + a[i]].push_back(i);
    }
    vector<int> dist_even(n, INF), dist_odd(n, INF);
    queue<int> q_even, q_odd;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            dist_even[i] = 0;
            q_even.push(i);
        } else {
            dist_odd[i] = 0;
            q_odd.push(i);
        }
    }
    while (!q_even.empty()) {
        int u = q_even.front(); q_even.pop();
        for (int v : rev_graph[u]) {
            if (dist_even[v] == INF) {
                dist_even[v] = dist_even[u] + 1;
                q_even.push(v);
            }
        }
    }
    while (!q_odd.empty()) {
        int u = q_odd.front(); q_odd.pop();
        for (int v : rev_graph[u]) {
            if (dist_odd[v] == INF) {
                dist_odd[v] = dist_odd[u] + 1;
                q_odd.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int res = (a[i] % 2 == 0) ? dist_odd[i] : dist_even[i];
        cout << (res == INF ? -1 : res) << " ";
    }
    cout << endl;
}
