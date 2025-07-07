#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<bool>> forbidden(n + 1, vector<bool>(n + 1, false));
        for (int i = 0; i < m; ++i) {
            int pos, val;
            cin >> pos >> val;
            forbidden[pos][val] = true;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int len = 1; len <= n; ++len) {
            for (int s = 1; s <= len; ++s) {
                bool valid = true;
                for (int shift = 0; shift < s; ++shift) {
                    for (int i = 0; i < s; ++i) {
                        int pos = len - s + 1 + i;
                        int val = (shift + i) % s + 1;
                        if (forbidden[pos][val]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        dp[len] = (dp[len] + dp[len - s]) % MOD;
                    }
                    valid = true;
                }
            }
        }

        cout << dp[n] << '\n';
    }

    return 0;
}