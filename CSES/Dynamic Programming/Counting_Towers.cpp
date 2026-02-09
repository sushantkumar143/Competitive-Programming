#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

long long fun(int level, int type, vector<vector<long long>>& dp) {
    if (level == 1)
        return 1;

    if (dp[level][type] != -1)
        return dp[level][type];

    long long ans;
    if (type == 0) {
        ans = ( fun(level - 1, 0, dp)
              + fun(level - 1, 1, dp) ) % MOD;
    } else {
        ans = ( (4LL * fun(level - 1, 0, dp)) % MOD
              + (2LL * fun(level - 1, 1, dp)) % MOD ) % MOD;
    }

    return dp[level][type] = ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<long long>> dp(n + 1, vector<long long>(2, -1));
        long long ans = (fun(n, 0, dp) + fun(n, 1, dp)) % MOD;
        cout << ans << '\n';
    }
}