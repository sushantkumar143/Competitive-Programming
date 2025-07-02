#include <bits/stdc++.h>
using namespace std;

int main() {

    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int& x : a) cin >> x;

        sort(a.rbegin(), a.rend()); 

        vector<long long> prefix(n);
        prefix[0] = a[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + a[i];
        }

        while (q--) {
            long long x;
            cin >> x;

            int lo = 0, hi = n - 1, ans = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (prefix[mid] >= x) {
                    ans = mid + 1;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
