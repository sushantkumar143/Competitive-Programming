#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isValidSplit(const vector<ll>& b) {
    ll total = accumulate(b.begin(), b.end(), 0LL);
    if (total % 2 != 0) return false;
    ll half = total / 2;
    ll sum = 0;
    for (int i = 0; i < b.size() - 1; ++i) {
        sum += b[i];
        if (sum == half) return true;
    }
    return false;
}

vector<ll> buildValidB(const vector<ll>& a) {
    // Try to find a prefix such that prefix sum == suffix sum
    int n = a.size();
    vector<ll> pre(n + 1, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i - 1];
    for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] + a[i - 1];

    for (int i = 1; i < n; ++i) {
        if (pre[i] == suf[i + 1]) {
            vector<ll> b = a;
            return b;
        }
    }

    // If no valid b found, try greedy reduction
    vector<ll> b(n, 0);
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum % 2 != 0) return {};

    ll half = sum / 2;
    ll running = 0;
    for (int i = 0; i < n; ++i) {
        if (running + a[i] <= half) {
            b[i] = a[i];
            running += a[i];
        } else {
            b[i] = half - running;
            running = half;
            break;
        }
    }
    if (running == half) return b;
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a) cin >> x;

        vector<vector<ll>> ops;

        int max_ops = 17;
        while (accumulate(a.begin(), a.end(), 0LL) > 0 && ops.size() < max_ops) {
            vector<ll> b = buildValidB(a);
            if (b.empty()) break;

            // Apply b to a
            for (int i = 0; i < n; ++i) {
                a[i] -= b[i];
            }

            ops.push_back(b);
        }

        if (accumulate(a.begin(), a.end(), 0LL) > 0) {
            cout << -1 << '\n';
        } else {
            cout << ops.size() << '\n';
            for (auto& op : ops) {
                for (auto val : op) cout << val << ' ';
                cout << '\n';
            }
        }
    }

    return 0;
}
