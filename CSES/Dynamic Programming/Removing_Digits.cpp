#include<bits/stdc++.h>
using namespace std;

// int fun(int n, vector<int>& dp) {
//     if(n == 0) return 0;
//     if(dp[n] != -1) return dp[n];

//     int ans = 1e9;
//     int x = n;
//     while(x) {
//         int digit = x%10;
//         x /= 10;
//         if(digit) ans = min(ans, 1+fun(n-digit, dp));
//     }

//     return dp[n] = ans;
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<int> dp(n+1, -1);
//     int ans = fun(n, dp);
//     cout << ans;
// }


int main() {
    int n;
    cin >> n;
    int steps = 0;

    while(n) {
        int maxi = 0;
        int temp = n;
        while(temp) {
            int digit = temp%10;
            maxi = max(maxi, digit);
            temp /= 10;
        }
        steps++;
        n -= maxi;
    }

    cout << steps;
}