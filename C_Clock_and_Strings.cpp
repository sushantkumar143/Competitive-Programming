#include <bits/stdc++.h>
using namespace std;

bool inArc(int x, int y, int z) {
    while (x != y) {
        if (x == z) return true;
        x = (x % 12) + 1; 
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        bool cInArc = inArc(a, b, c);
        bool dInArc = inArc(a, b, d);

        if (cInArc ^ dInArc) cout << "YES\n"; 
        else cout << "NO\n";
    }
    return 0;
}
