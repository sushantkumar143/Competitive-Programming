#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int cnt = count(s.begin(), s.end(), '1'); 

        int ans = cnt * (cnt - 1) + (n - cnt) * (cnt + 1);
        cout << ans << "\n";
    }
    return 0;
}
