#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int odd_cnt = 0;
        for (int f : freq) if (f % 2) odd_cnt++;

        int len_remain = n - k;

        if (odd_cnt <= k + (len_remain % 2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
