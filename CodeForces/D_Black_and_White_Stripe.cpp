#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int whiteCount = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'W') whiteCount++;
        }
        int ans = whiteCount;

        for (int i = k; i < n; i++) {
            if (s[i-k] == 'W') whiteCount--; 
            if (s[i] == 'W') whiteCount++;  
            ans = min(ans, whiteCount);
        }

        cout << ans << "\n";
    }
    return 0;
}
