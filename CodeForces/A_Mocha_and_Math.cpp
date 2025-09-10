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
        int x;
        cin >> x;
        int result = x;
        for (int i = 1; i < n; i++) {
            cin >> x;
            result &= x;
        }
        cout << result << "\n";
    }
    return 0;
}
