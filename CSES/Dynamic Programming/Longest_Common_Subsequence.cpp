#include <bits/stdc++.h>
using namespace std;

// int fun(int i, int j, vector<int>& arr1, vector<int>& arr2, vector<vector<int>>& dp) {
//     if(i<0 || j<0) return 0;
//     if(dp[i][j] != -1) return dp[i][j];

//     if(arr1[i] == arr2[j]) return dp[i][j] = 1 + fun(i-1, j-1, arr1, arr2, dp);

//     return dp[i][j] = max(fun(i, j-1, arr1, arr2, dp), fun(i-1, j, arr1, arr2, dp));
// }

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n), arr2(m); 
    for(int& x : arr1) cin >> x;
    for(int& x : arr2) cin >> x;

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << fun(n-1, m-1, arr1, arr2, dp);

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(arr1[i-1] == arr2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    vector<int> ans;
    int i = n;
    int j = m;
    while(i > 0 && j > 0) {
        if(arr1[i-1] == arr2[j-1]) {
            ans.push_back(arr1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    cout << dp[n][m] << '\n';
    for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << " "; 
}