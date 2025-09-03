#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >> t;
    while (t--) {
        int a1,a2,b1,b2;
        cin >> a1 >> a2 >> b1 >> b2;
        int ans = 0;

        int winS1 = 0, winL1 = 0;
        if (a1 > b1) ++winS1; else if (a1 < b1) ++winL1;
        if (a2 > b2) ++winS1; else if (a2 < b2) ++winL1;
        if (winS1 > winL1) ans += 2;

        int winS2 = 0, winL2 = 0;
        if (a1 > b2) ++winS2; else if (a1 < b2) ++winL2;
        if (a2 > b1) ++winS2; else if (a2 < b1) ++winL2;
        if (winS2 > winL2) ans += 2;

        cout << ans << '\n';
    }
    return 0;
}
