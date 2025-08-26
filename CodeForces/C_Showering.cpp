#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s, m;
        cin >> n >> s >> m;

        vector<pair<long long, long long>> tasks(n);
        for (int i = 0; i < n; i++) {
            cin >> tasks[i].first >> tasks[i].second;
        }

        bool possible = false;

        // Before first task
        if (tasks[0].first >= s) possible = true;

        // Between tasks
        for (int i = 0; i + 1 < n; i++) {
            if (tasks[i+1].first - tasks[i].second >= s) {
                possible = true;
                break;
            }
        }

        // After last task
        if (m - tasks[n-1].second >= s) possible = true;

        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
