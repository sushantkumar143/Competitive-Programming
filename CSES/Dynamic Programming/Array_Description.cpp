#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<int> arr;

int dp[100001][101];

int fun(int idx, int cur) {
    if (idx == 0) {
        if (arr[0] == 0 || arr[0] == cur) return 1;
        return 0;
    }

    if (dp[idx][cur] != -1) return dp[idx][cur];

    if (arr[idx] != 0 && arr[idx] != cur) return dp[idx][cur] = 0;

    long long left = 0, mid = 0, right = 0;

    // left: cur - 1
    if (cur - 1 >= 1) left = fun(idx - 1, cur - 1);

    // mid: cur
    mid = fun(idx - 1, cur);

    // right: cur + 1
    if (cur + 1 <= m) right = fun(idx - 1, cur + 1);

    return dp[idx][cur] = (left + mid + right) % MOD;
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    for (int &x : arr) cin >> x;

    memset(dp, -1, sizeof(dp));

    long long ans = 0;

    if (arr[n - 1] != 0) {
        ans = fun(n - 1, arr[n - 1]);
    } 
    else {
        for (int v = 1; v <= m; v++) {
            ans = (ans + fun(n - 1, v)) % MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}
