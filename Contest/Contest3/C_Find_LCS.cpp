#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int &x : arr1) cin >> x;
    for (int &x : arr2) cin >> x;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (arr1[i-1] == arr2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0){
        if (arr1[i-1] == arr2[j-1]){
            lcs.push_back(arr1[i-1]);
            i--;    
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << lcs.size() << '\n';
    for (int x : lcs) cout << x << ' ';
    cout << '\n';

    return 0;
}
