#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    if (!(cin >> k)) return 0;

    vector<int> a(12);
    for (int i = 0; i < 12; ++i) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    int sum = 0, months = 0;
    for (int x : a) {
        if (sum >= k) break;
        sum += x;
        ++months;
    }

    if (sum < k) cout << -1 << '\n';
    else cout << (k == 0 ? 0 : months) << '\n';
    return 0;
}
