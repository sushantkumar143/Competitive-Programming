#include<bits/stdc++.h>
using namespace std;

int fun(int idx, int k, vector<int>& arr, vector<int>& dp) {
    if(idx <= 0) return 0;
    if(dp[idx] != -1) return dp[idx];

    int ways = 1e9;
    for(int i=1; i<=k && idx-i >= 0; i++) {
        ways = min(ways, fun(idx-i, k, arr, dp) + abs(arr[idx] - arr[idx-i]));
    }

    return dp[idx] = ways;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    vector<int> dp(n, -1);
    int ans = fun(n-1, k, arr, dp);
    cout << ans;

    return 0;
}