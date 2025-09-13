#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    if (!(cin >> t)) return 0;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) cin >> arr[i];

        vector<int> freq(n+1, 0);
        for (int x : arr) ++freq[x];

        bool ok = true;
        vector<int> allowed(n+1, 0);

        for (int v = 1; v <= n; ++v) {
            if (freq[v] % k != 0) {
                ok = false;
                break;
            }
            allowed[v] = freq[v] / k;
        }
        
        if (!ok) {
            cout << 0 << '\n';
            continue;
        }
        vector<int> cur(n+1, 0);
        ll ans = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            ++cur[arr[r]];
            while (cur[arr[r]] > allowed[arr[r]]) {
                --cur[arr[l]];
                ++l;
            }

            ans  +=  (r - l + 1);
        }

        cout <<  ans << '\n';
    }

}
