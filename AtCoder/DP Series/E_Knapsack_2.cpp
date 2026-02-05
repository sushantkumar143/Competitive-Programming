// #include<bits/stdc++.h>
// using namespace std;

// long long fun(long long idx, long long wt, vector<vector<long long>>& arr, vector<vector<long long>>& dp) {
//     if(idx < 0 || wt == 0) return 0;
//     if(dp[idx][wt] != -1) return dp[idx][wt];

//     long long notTake = fun(idx-1, wt, arr, dp);
//     long long take = 0;
//     if(wt >= arr[idx][0]) take = arr[idx][1] + fun(idx-1, wt-arr[idx][0], arr, dp);

//     return dp[idx][wt] = max(take, notTake);
// }

// int main() {
//     long long n, wt;
//     cin >> n >> wt;
//     vector<vector<long long>> arr(n, vector<long long>(2));
    
//     for(int i=0; i<n; i++) {    
//         cin >> arr[i][0] >> arr[i][1];
//     }
    
//     vector<vector<long long>> dp(n+1, vector<long long>(wt+1, 0));
//     // long long ans = fun(n-1, wt, arr, dp);
//     // cout << ans;

//     for(int i=1; i<=n; i++) {
//         for(int w=0; w<=wt; w++) {
//             long long notTake = dp[i-1][w];
//             long long take = 0;
//             if(w >= arr[i-1][0]) take = arr[i-1][1] + dp[i-1][w-arr[i-1][0]];

//             dp[i][w] = max(take, notTake);
//         }
//     }

//     cout << dp[n][wt];
// }




#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long W;
    cin >> N >> W;

    vector<long long> w(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    int MAXV = 100000; // max total value
    const long long INF = 1e18;

    vector<long long> dp(MAXV + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int val = MAXV; val >= v[i]; val--) {
            dp[val] = min(dp[val], dp[val - v[i]] + w[i]);
        }
    }

    long long ans = 0;
    for (int val = 0; val <= MAXV; val++) {
        if (dp[val] <= W)
            ans = val;
    }

    cout << ans << "\n";
    return 0;
}