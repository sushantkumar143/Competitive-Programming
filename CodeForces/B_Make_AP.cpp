#include <bits/stdc++.h>
using namespace std;

bool canMakeAP(long long a, long long b, long long c) {
    if ((2 * b - c) > 0 && (2 * b - c) % a == 0) return true;
    if ((a + c) % (2 * b) == 0 && (a + c) / (2 * b) > 0) return true;
    if ((2 * b - a) > 0 && (2 * b - a) % c == 0) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << (canMakeAP(a, b, c) ? "YES\n" : "NO\n");
    }
    return 0;
}
