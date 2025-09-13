#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    long long ts = 0;
    vector<long long> odds;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;

        ts += a;
        if (a % 2 != 0) {
            odds.push_back(a);
        }
    }

    if (odds.empty()) {
        cout << 0 << '\n';
        return;
    }

    sort(odds.begin(), odds.end());

    int k = odds.size();
    int num_to_sacrifice = k / 2;

    for (int i = 0; i < num_to_sacrifice; ++i) {
        ts -= odds[i];
    }
    
    cout << ts << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}