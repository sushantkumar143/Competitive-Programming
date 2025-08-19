#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int d = abs(a - b);
        int moves = (d + 2*c - 1) / (2*c); // ceil division
        cout << moves << "\n";
    }
    return 0;
}
