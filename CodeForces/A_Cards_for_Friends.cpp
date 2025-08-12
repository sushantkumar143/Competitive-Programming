#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long w, h, n;
        cin >> w >> h >> n;
        long long pieces = 1;
        while ((w % 2) == 0) {
            w /= 2;
            pieces *= 2;
        }
        while ((h % 2) == 0) {
            h /= 2;
            pieces *= 2;
        }
        cout << (pieces >= n ? "YES\n" : "NO\n");
    }
    return 0;
}
