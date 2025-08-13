#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<long long> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        long long amin = *min_element(a.begin(), a.end());
        long long bmin = *min_element(b.begin(), b.end());

        long long moves = 0;
        for (int i = 0; i < n; ++i) {
            moves += max(a[i] - amin, b[i] - bmin);
        }
        cout << moves << "\n";
    }
    return 0;
}
