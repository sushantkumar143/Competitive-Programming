#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int sum = a + 2*b;

        if (sum % 2 != 0) {
            cout << "NO\n";
            continue;
        }

        int target = sum / 2;

        if (target % 2 == 1 && a == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
