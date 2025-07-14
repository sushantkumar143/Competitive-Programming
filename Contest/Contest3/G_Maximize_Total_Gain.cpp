#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
int a[MAX][MAX];
int dp1[MAX][MAX];
int dp2[MAX][MAX];
int dp3[MAX][MAX];
int dp4[MAX][MAX];
int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);

    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp2[i][j] = a[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);

    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);

    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 1; --j)
            dp4[i][j] = a[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);

    int ans = 0;

    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < m; ++j) {
            int option1 = dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j];
            int option2 = dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1];
            ans = max({ans, option1, option2});
        }
    }

    cout << ans << '\n';
    return 0;
}
