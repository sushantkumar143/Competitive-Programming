#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n;

long long fun(int i, int j, vector<vector<char>>& arr, vector<vector<int>>& dp) {
    if(i<0 || j<0 || i>=n || j>=n || arr[i][j] == '*') return 0;
    if(!i && !j) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    int up = fun(i-1, j, arr, dp);
    int left = fun(i, j-1, arr, dp);

    return dp[i][j] = (up + left) % MOD;
}

int main() {
    cin >> n;

    vector<vector<char>> arr(n, vector<char>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    long long ans = fun(n-1, n-1, arr, dp);
    cout << ans;
}