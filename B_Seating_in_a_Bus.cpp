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
        for (int i = 0; i < n; i++) cin >> a[i];

        int L = a[0], R = a[0]; // first passenger can sit anywhere
        bool ok = true;

        for (int i = 1; i < n; i++) {
            int seat = a[i];
            if (seat == L - 1) {
                L--; // expand left
            } else if (seat == R + 1) {
                R++; // expand right
            } else {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
