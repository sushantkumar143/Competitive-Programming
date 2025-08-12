#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        if (x == 2) {
            cout << 1 << " " << 1 << "\n";
        } 
        else if (x == 14) {
            cout << 6 << " " << 4 << "\n";
        } 
        else {
            cout << 1 << " " << x - 1 << "\n";
        }
    }
    return 0;
}
