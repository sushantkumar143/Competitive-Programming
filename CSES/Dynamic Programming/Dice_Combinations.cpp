#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;

long long fun(int sm, int n, vector<int>& dp) {
    if(sm == n) return 1;
    if(sm > n) return 0;
    if(dp[sm] != -1) return dp[sm];

    long long ways = 0;
    for(int i=1; i<=6; i++) {
        ways = (ways + fun(sm+i, n, dp))%MOD;
    }

    return dp[sm] = ways;
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);

    long long ans = fun(0, n, dp);
    cout << ans;
    return 0;
}