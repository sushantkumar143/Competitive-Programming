#include<bits/stdc++.h>
using namespace std;

long long fun(long long idx, long long wt, vector<vector<long long>>& arr, vector<vector<long long>>& dp) {
    if(idx < 0 || wt == 0) return 0;
    if(dp[idx][wt] != -1) return dp[idx][wt];

    long long notTake = fun(idx-1, wt, arr, dp);
    long long take = 0;
    if(wt >= arr[idx][0]) take = arr[idx][1] + fun(idx-1, wt-arr[idx][0], arr, dp);

    return dp[idx][wt] = max(take, notTake);
}

int main() {
    long long n, wt;
    cin >> n >> wt;
    vector<vector<long long>> arr(n, vector<long long>(2));
    
    for(int i=0; i<n; i++) {    
        cin >> arr[i][0] >> arr[i][1];
    }
    
    vector<vector<long long>> dp(n, vector<long long>(wt+1, -1));
    long long ans = fun(n-1, wt, arr, dp);
    cout << ans;
}