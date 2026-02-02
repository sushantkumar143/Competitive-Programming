#include<bits/stdc++.h>
using namespace std;

int fun(int idx, vector<int>& arr, int target, vector<vector<int>>& dp) {
    if(!target) return 0;
    if(idx == arr.size() || target<0) return 1e9; 
    if(dp[idx][target] != -1) return dp[idx][target];

    int take = 1 + fun(idx, arr, target-arr[idx], dp);
    int NotTake = fun(idx+1, arr, target, dp);

    return dp[idx][target] = min(take, NotTake);
}

// int main() {
//     int n, target;
//     cin >> n >> target;

//     vector<int> arr(n);
//     for (int &x : arr) cin >> x;
//     vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
    
//     int ans = fun(0, arr, target, dp);
    
//     if (ans >= 1e9) cout << -1;
//     else cout << ans;


//     return 0;
// }


int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for(int &x : arr) cin >> x;

    const int INF = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, INF));

    dp[n][0] = 0;

    for(int idx = n - 1; idx >= 0; idx--) {
        for(int sm = 0; sm <= target; sm++) {
            int notTake = dp[idx + 1][sm];
            int take = INF;
            if(sm - arr[idx] >= 0) {
                take = 1 + dp[idx][sm - arr[idx]];
            }
            dp[idx][sm] = min(take, notTake);
        }
    }

    if(dp[0][target] >= INF) cout << -1;
    else cout << dp[0][target];

    return 0;
}