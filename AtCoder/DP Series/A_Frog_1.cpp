#include<bits/stdc++.h>
using namespace std;

int fun(int idx, vector<int>& arr, vector<int>& dp) {
    if(idx < 1) return 0;
    if(dp[idx] != -1) return dp[idx];

    int oneStep = fun(idx-1, arr, dp) + abs(arr[idx] - arr[idx-1]);
    int twoStep = 1e9;
    if(idx-2 >= 0) twoStep = fun(idx-2, arr, dp) + abs(arr[idx] - arr[idx-2]);

    return dp[idx] = min(oneStep, twoStep);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& x : arr) cin >> x;
    vector<int> dp(n, -1);

    int ans = fun(n-1, arr, dp);
    cout << ans;

    return 0;
}