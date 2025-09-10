#include <bits/stdc++.h>
using namespace std;

int LIS_length(vector<int>& a) {
    vector<int> lis;
    for (int x : a) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }
    return lis.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        int max_freq = 0;
        for (auto &p : freq) {
            max_freq = max(max_freq, p.second);
        }

        int lis_len = LIS_length(a);
        cout << max(lis_len, max_freq) << "\n";
    }

    return 0;
}
