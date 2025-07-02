#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool canSort(vector<int> &a, int m, int k) {
    int g = gcd(m, k);
    vector<int> mapped;
    for (int x : a) {
        mapped.push_back(x % g);
    }

    // If mapped is not non-decreasing, it's impossible
    for (int i = 0; i + 1 < mapped.size(); ++i) {
        if (mapped[i] > mapped[i + 1]) {
            return false;
        }
    }

    // Check circular jumps don't mess ordering
    // Now simulate applying (a[i] + x*k) % m to reach some sorted order
    // Greedy check actual mod-m values can be sorted by rotation
    vector<int> b = a;
    auto cmp = [&](int u, int v) {
        for (int t = 0; t < m / g; ++t) {
            int new_u = (u + 1LL * t * k) % m;
            int new_v = (v + 1LL * t * k) % m;
            if (new_u <= new_v) return true;
        }
        return false;
    };

    for (int i = 0; i + 1 < b.size(); ++i) {
        int u = b[i];
        int v = b[i + 1];
        bool ok = false;
        for (int step1 = 0; step1 < m / g && !ok; ++step1) {
            int u_val = (u + 1LL * step1 * k) % m;
            for (int step2 = 0; step2 < m / g; ++step2) {
                int v_val = (v + 1LL * step2 * k) % m;
                if (u_val <= v_val) {
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) return false;
    }

    return true;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int i, x;
                cin >> i >> x;
                a[i - 1] = x;
            } else {
                int k;
                cin >> k;
                cout << (canSort(a, m, k) ? "YES\n" : "NO\n");
            }
        }
    }
    return 0;
}
