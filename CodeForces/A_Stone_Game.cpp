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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int min_pos = min_element(a.begin(), a.end()) - a.begin() + 1;
        int max_pos = max_element(a.begin(), a.end()) - a.begin() + 1;

        int case1 = max(min_pos, max_pos);

        int case2 = max(n - min_pos + 1, n - max_pos + 1);

        int case3 = min(min_pos + (n - max_pos + 1),
                        max_pos + (n - min_pos + 1));

        cout << min({case1, case2, case3}) << "\n";
    }
}
