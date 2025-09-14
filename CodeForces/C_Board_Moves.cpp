#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long m = (n - 1) / 2; 
        long long ans = (4LL * m * (m + 1) * (2 * m + 1)) / 3;
        cout << ans << "\n";
    }
    return 0;
}
