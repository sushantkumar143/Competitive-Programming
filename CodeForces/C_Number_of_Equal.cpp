#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    long long ans = 0;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] == b[j]) {
            int cntA = 0, cntB = 0;
            int val = a[i];

            while (i < n && a[i] == val) {
                cntA++;
                i++;
            }

            while (j < m && b[j] == val) {
                cntB++;
                j++;
            }

            ans += 1LL * cntA * cntB;
        } 
        else if (a[i] < b[j]) {
            i++;
        } 
        else {
            j++;
        }
    }

    cout << ans << "\n";
    return 0;
}
