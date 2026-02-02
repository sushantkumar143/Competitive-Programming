#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// int fun(int idx, int target, vector<int> arr, vector<vector<int>>& dp) {
//     if(!target) return 1;
//     if(target<0 || idx == arr.size()) return 0;
//     if(dp[idx][target] != -1) return dp[idx][target];

//     int notTake = fun(idx+1, target, arr, dp);   
//     int take = fun(idx, target-arr[idx], arr, dp);   

//     return dp[idx][target] = (take + notTake) % MOD;
// }

// int main() {
//     int n, target;
//     cin >> n >> target;

//     vector<int> arr(n);
//     for(int& x : arr) cin >> x;

//     vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
//     int ans = fun(0, target, arr, dp);
//     cout << ans;
// }


int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    
    dp[n][0] = 1;
    for(int i=n-1; i>=0; i--) {
        for(int t=0; t<=target; t++) {
            int notTake = dp[i+1][t];   
            int take = 0;
            if (t - arr[i] >= 0)
                take = dp[i][t - arr[i]];  

            dp[i][t] = (take + notTake) % MOD;
        }
    }

    cout << dp[0][target];
}