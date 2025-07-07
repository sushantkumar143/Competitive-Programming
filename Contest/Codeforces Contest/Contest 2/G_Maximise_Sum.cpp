#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll prefixMinSum(const vector<ll>& a) {
    ll sum = 0, currMin = a[0];
    sum += currMin;
    for (int i = 1; i < a.size(); ++i) {
        currMin = min(currMin, a[i]);
        sum += currMin;
    }
    return sum;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a) cin >> x;
        vector<ll> best(n, 0);
        ll base = prefixMinSum(a);
        for (int i = 0; i < n; ++i)
            best[0] = max(best[0], base);
        for (int i = 0; i < n; ++i) {
            ll ai = a[i];
            for (int j = i + 1; j < n; ++j) {
                vector<ll> b = a;
                b[i] += b[j];
                b[j] = 0;
                ll cost = j - i;
                ll score = prefixMinSum(b);
                best[cost] = max(best[cost], score);
            }
        }
        for (int i = n - 2; i >= 0; --i)
            best[i] = max(best[i], best[i + 1]);

        for (int i = 0; i < n; ++i)
            cout << best[i] << " ";
        cout << '\n';
    }
    return 0;
}