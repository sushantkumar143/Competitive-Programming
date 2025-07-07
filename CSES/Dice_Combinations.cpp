#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int fun(int n, vector<int>& dp) {
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];

    int ans = 0;
    for (int i = 1; i <= 6; ++i) {
        if (n - i >= 0) {
            ans = (ans + fun(n - i, dp)) % MOD;
        }
    }
    return dp[n] = ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << fun(n, dp) << endl;
}
