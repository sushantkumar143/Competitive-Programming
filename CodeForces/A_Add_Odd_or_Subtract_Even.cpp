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
        long long diff = b - a;

        if (diff == 0) {
            cout << 0 << "\n";
        } 
        else if (diff > 0) {
            if (diff % 2 != 0) cout << 1 << "\n";
            else cout << 2 << "\n";
        } 
        else { 
            diff = -diff;
            if (diff % 2 == 0) cout << 1 << "\n";
            else cout << 2 << "\n";
        }
    }
    return 0;
}
