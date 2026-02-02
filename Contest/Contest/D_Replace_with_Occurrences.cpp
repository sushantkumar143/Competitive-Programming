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

        vector<vector<int>> groups(n + 1);
        for (int i = 0; i < n; i++) {
            int bValue;
            cin >> bValue;
            groups[bValue].push_back(i);
        }

        bool possible = true;
        for (int k = 1; k <= n; k++) {
            if (groups[k].size() % k != 0) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << -1 << "\n";
            continue;
        }

        vector<int> a(n);
        int valueToAssign = 1;

        for (int k = 1; k <= n; k++) {
            auto &indices = groups[k];
            for (int i = 0; i < (int)indices.size(); i += k) {
                for (int j = 0; j < k; j++) {
                    int originalIndex = indices[i + j];
                    a[originalIndex] = valueToAssign;
                }
                valueToAssign++;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
