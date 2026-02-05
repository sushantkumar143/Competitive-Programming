#include<bits/stdc++.h>
using namespace std;

bool fun(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (idx == 0) return target == arr[0];

    if(dp[idx][target] != -1) return dp[idx][target];

    bool notTake = fun(idx-1, target, arr, dp);
    bool take = false;
    if(target >= arr[idx]) take = fun(idx-1, target - arr[idx], arr, dp);

    return dp[idx][target] = (take || notTake);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    // vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    
    // bool ans = fun(n-1, k, arr, dp);
    // cout << ans << '\n';


    vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = true;
    dp[1][arr[0]] = true;

    for(int i=1; i<=n; i++) {
        for(int sm=0; sm<=k; sm++) {
            bool notTake = dp[i-1][sm];
            bool take = false;
            if(sm >= arr[i]) take = dp[i-1][sm - arr[i-1]];

            dp[i][sm] = (take || notTake);
        }
    }

    cout << dp[n][k];
}