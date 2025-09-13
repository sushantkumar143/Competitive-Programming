#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;

        if (x != 1) {
            // Always possible: just use all 1's
            cout << "YES\n" << n << "\n";
            for (int i = 0; i < n; i++) cout << 1 << " ";
            cout << "\n";
        } else {
            if (n % 2 == 0) {
                // Use only 2's
                cout << "YES\n" << n / 2 << "\n";
                for (int i = 0; i < n / 2; i++) cout << 2 << " ";
                cout << "\n";
            } else if (k >= 3) {
                // Use one 3 and rest 2's
                cout << "YES\n" << (n - 3) / 2 + 1 << "\n";
                cout << 3 << " ";
                for (int i = 0; i < (n - 3) / 2; i++) cout << 2 << " ";
                cout << "\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
