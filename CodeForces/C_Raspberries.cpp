#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = INT_MAX;

        if (k == 2) {
            for (int x : a) {
                ans = min(ans, (x % 2 == 0 ? 0 : 1));
            }
        }
        else if (k == 3) {
            for (int x : a) {
                int need = (3 - (x % 3)) % 3;
                ans = min(ans, need);
            }
        }
        else if (k == 5) {
            for (int x : a) {
                int need = (5 - (x % 5)) % 5;
                ans = min(ans, need);
            }
        }
        else if (k == 4) {
            int total2 = 0;

            for (int x : a) {
                int cnt = 0, y = x;
                while (y % 2 == 0) { cnt++; y /= 2; }
                total2 += cnt;
            }

            if (total2 >= 2) {
                ans = 0;
            } 
            else {
                for (int x : a) {
                    int need = (4 - (x % 4)) % 4;
                    ans = min(ans, need);
                }

                vector<int> costs;
                for (int x : a) {
                    int need = (2 - (x % 2)) % 2;
                    costs.push_back(need);
                }
                
                sort(costs.begin(), costs.end());
                if (costs.size() >= 2)
                    ans = min(ans, costs[0] + costs[1]);
            }
        }

        cout << ans << "\n";
    }
}
