#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    // cout << dp[n][m];

    string s = "";
    int i = n;
    int j = m;

    while(i && j) {
        if(s1[i-1] == s2[j-1]) {
            s += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    reverse(s.begin(), s.end());
    cout << s;
}