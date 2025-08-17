#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long ans = (k + n - 1) / n; // ceil(k/n)
        cout << ans << "\n";
    }
    return 0;
}
