#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2) odd++;
            else even++;
        }

        bool possible = false;
        // try choosing odd count of odd numbers
        for (int k = 1; k <= odd; k += 2) {
            if (k <= x && (x - k) <= even) {
                possible = true;
                break;
            }
        }

        cout << (possible ? "Yes" : "No") << "\n";
    }
    return 0;
}
