#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long p = 1;
        while (p <= n) p <<= 1;
        p >>= 1;

        cout << p - 1 << "\n";
    }
    return 0;
}
