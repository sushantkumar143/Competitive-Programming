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

        int oddParity = a[0] % 2;
        bool oddOK = true;
        for (int i = 0; i < n; i += 2) {
            if (a[i] % 2 != oddParity) {
                oddOK = false;
                break;
            }
        }

        int evenParity = (n > 1 ? a[1] % 2 : 0);
        bool evenOK = true;
        for (int i = 1; i < n; i += 2) {
            if (a[i] % 2 != evenParity) {
                evenOK = false;
                break;
            }
        }

        if (oddOK && evenOK) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
