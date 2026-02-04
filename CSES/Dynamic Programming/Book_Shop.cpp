#include<bits/stdc++.h>
using namespace std;

// int fun(int idx, int wt, vector<int>& price, vector<int>& pages, vector<vector<int>>& dp) {
//     if(wt <= 0 || idx<0) return 0;
//     if(dp[idx][wt] != -1) return dp[idx][wt];

//     int notTake = fun(idx-1, wt, price, pages, dp);
//     int take = INT_MIN;
//     if(wt >= price[idx]) take = pages[idx] + fun(idx-1, wt-price[idx], price, pages, dp);

//     return dp[idx][wt] = max(take, notTake);
// }

// int main() {
//     int n, x;
//     cin >> n >> x;

//     vector<int> price(n), pages(n);
//     for(int& p : price) cin >> p;
//     for(int& p : pages) cin >> p;

//     vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
//     int ans = fun(n-1, x, price, pages, dp);
//     cout << ans;
// }


int main() {
    int n, x;
    cin >> n >> x;

    vector<int> price(n), pages(n);
    for(int& p : price) cin >> p;
    for(int& p : pages) cin >> p;

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for(int i=1; i<=n; i++) {
        for(int wt=0; wt<=x; wt++) {
            int notTake = dp[i-1][wt];
            int take = INT_MIN;
            if(wt >= price[i-1]) take = pages[i-1] + dp[i-1][wt-price[i-1]];

            dp[i][wt] = max(take, notTake);
        }
    }

    cout << dp[n][x];
}