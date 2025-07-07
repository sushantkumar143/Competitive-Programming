#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> b(n);
        for (ll& x : b) cin >> x;

        sort(b.begin(), b.end());

        ll x = 1;
        for (int i = 0; i < n - 1; ++i) {
            ll g = gcd(b[i], b[i + 1]);
            ll ratio = b[i + 1] / g;
            x = lcm(x, ratio);
        }

        cout << x << '\n';
    }

    return 0;
}