#include<bits/stdc++.h>
using namespace std;

int fun(int idx, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if(idx < 0) return 0;
    if(dp[idx][last] != -1) return dp[idx][last];

    int total = 0;
    for(int i=0; i<3; i++) {
        if(last != i) {
            total = max(total, arr[idx][i] + fun(idx-1, i, arr, dp));
        }
    }

    return dp[idx][last] = total;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> arr[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int ans = fun(n-1, 3, arr, dp);
    cout << ans;
}