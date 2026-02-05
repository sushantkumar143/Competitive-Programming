#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;

long long fun(int i, int j, vector<vector<char>>& arr, vector<vector<long long>>& dp) {
    if(!i && !j) return 1;
    if(i<0 || j<0 || arr[i][j] == '#') return 0;
    if(dp[i][j] != -1) return dp[i][j];

    long long up = fun(i-1, j, arr, dp);
    long long left = fun(i, j-1, arr, dp);

    return dp[i][j] = (up + left) % MOD;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }
    
    vector<vector<long long>> dp(n+1, vector<long long>(m+1, -1));
    long long ans = fun(n-1, m-1, arr, dp);
    cout << ans;
}