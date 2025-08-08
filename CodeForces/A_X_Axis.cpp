#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        int sec = x + y + z - max({x, y, z}) - min({x, y, z});
        int ans = abs(x - sec) + abs(y - sec) + abs(z - sec);
        cout << ans << '\n';
    }
}
