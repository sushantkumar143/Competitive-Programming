#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans += abs(a[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
