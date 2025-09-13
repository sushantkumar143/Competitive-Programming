#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long n = 2 * abs(a - b); 

        if (a > n || b > n || c > n || n == 0) {
            cout << -1 << "\n";
            continue;
        }

        long long d = c + n / 2;
        if (d > n) d -= n;

        cout << d << "\n";
    }

    return 0;
}
