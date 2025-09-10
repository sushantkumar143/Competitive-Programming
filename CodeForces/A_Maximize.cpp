#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        if (x % 2 == 0) cout << x / 2 << '\n';
        else cout << x - 1 << '\n';
    }
    return 0;
}
