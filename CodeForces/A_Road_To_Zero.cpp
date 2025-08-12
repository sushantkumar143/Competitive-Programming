#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, a, b;
        cin >> x >> y;
        cin >> a >> b;

        long long m = min(x, y);
        long long d = abs(x - y);
        long long cost = m * min(b, 2 * a) + d * a;

        cout << cost << "\n";
    }
    return 0;
}
