#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// int fun(int n, int target, vector<int> arr, vector<int>& dp) {
//     if(!target) return 1;
//     if(target<0) return 0;
//     if(dp[target] != -1) return dp[target];

//     int ways = 0;
//     for(int i=0; i<n; i++) {
//         ways = (ways + fun(n, target-arr[i], arr, dp)) % MOD;
//     }    

//     return dp[target] = ways;
// }

// int main() {
//     int n, target;
//     cin >> n >> target;

//     vector<int> arr(n);
//     for(int& x : arr) cin >> x;

//     vector<int> dp(target+1, -1);
//     int ans = fun(n, target, arr, dp);
//     cout << ans;
// }


int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    vector<int> dp(target+1, 0);
    dp[0] = 1;
    
    for(int t=0; t<=target; t++) {
        for(int i=0; i<n; i++) {
            if(t-arr[i] >= 0) dp[t] = (dp[t] + dp[t-arr[i]]) % MOD;
        }
    }

    cout << dp[target];
}