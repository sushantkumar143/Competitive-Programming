#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        if (a % 2 != 0 && b % 2 != 0) {
            cout << a * b + 1 << "\n";
        } else if (a % 2 == 0 && b % 2 != 0) {
            cout << -1 << "\n";
        } else if (a % 2 != 0 && b % 2 == 0) {
            if (b % 4 != 0) {
                cout << -1 << "\n";
            } else {
                cout << max(2 * a + b / 2, a * (b / 2) + 2) << "\n";
            }
        } else { // both even
            cout << max(a + b, a * (b / 2) + 2) << "\n";
        }
    }

}
