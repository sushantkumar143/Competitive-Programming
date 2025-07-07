#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 1e9); 
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int temp = i;
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            if (digit == 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - digit]);
        }
    }

    cout << dp[n] << endl;
    return 0;
}
