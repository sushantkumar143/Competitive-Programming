#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        long long M = max({x, y, z});

        int cnt = 0;
        if (x == M) cnt++;
        if (y == M) cnt++;
        if (z == M) cnt++;

        if (cnt < 2) {
            cout << "NO\n";
        } 
        else {
            cout << "YES\n";
            if (x == M && y == M) {
                cout << M << " " << z << " " << z << "\n";
            } 
            else if (x == M && z == M) {
                cout << y << " " << M << " " << y << "\n";
            } 
            else {
                cout << x << " " << x << " " << M << "\n";
            }
        }
    }
}
