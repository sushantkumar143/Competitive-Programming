#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        unordered_map<int, long long> freq;
        for (int i = 0; i < n; ++i) {
            freq[a[i] - i]++;
        }

        long long ans = 0;
        for (auto &[key, count] : freq) {
            ans += (count * (count - 1)) / 2;
        }

        cout << ans << '\n';
    }
    return 0;
}
