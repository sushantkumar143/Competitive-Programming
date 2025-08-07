#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        ll total = 0;
        vector<ll> gains;

        for (int i = 0; i < n; ++i) {
            total += abs(a[i] - b[i]);
        }

        for (int i = 0; i < n; ++i) {
            // In-place pair (i, j), just try with i and j = i
            // Since each round takes a pair, we consider gain from 2 indices

            gains.push_back(0); // no gain if not optimized

            // But we can make real gains from pairs: try adjacent
            if (i + 1 < n) {
                vector<ll> vals = {a[i], a[i+1], b[i], b[i+1]};
                sort(vals.begin(), vals.end());
                ll max_gain = 0;

                // Try all pairings
                for (int p = 0; p < 4; ++p) {
                    for (int q = 0; q < 4; ++q) {
                        if (p == q) continue;
                        int r = -1, s = -1;
                        for (int x = 0; x < 4; ++x) {
                            if (x != p && x != q) {
                                if (r == -1) r = x;
                                else s = x;
                            }
                        }
                        ll new_val = abs(vals[p] - vals[q]) + abs(vals[r] - vals[s]);
                        ll old_val = abs(a[i] - b[i]) + abs(a[i+1] - b[i+1]);
                        max_gain = max(max_gain, new_val - old_val);
                    }
                }

                gains.push_back(max_gain);
            }
        }

        sort(gains.rbegin(), gains.rend());
        ll result = total + accumulate(gains.begin(), gains.begin() + min(k, (int)gains.size()), 0LL);
        cout << result << '\n';
    }
    return 0;
}
