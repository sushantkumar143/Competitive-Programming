#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n, 1));

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }

    cout << a[n-1][n-1] << "\n";
    return 0;
}


// Method 2: Direct Formula (Binomial Coefficient)

// Answer = nCr  ->  (n-1) C (2n - 2)
// (n - 1
// 2n - 2)

#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r) {
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << nCr(2*n - 2, n - 1) << "\n";
    return 0;
}
