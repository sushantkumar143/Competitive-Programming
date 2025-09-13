#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long m;
        cin >> m;
        long long p = 1;
        while (p * 10 <= m) p *= 10;
        cout << (m - p) << '\n';
    }
    return 0;
}
