#include <bits/stdc++.h>
using namespace std;

void removeBag(map<long long, int>& weightsCount, long long weight) {
    if (--weightsCount[weight] == 0)
        weightsCount.erase(weight);
}

void solve() {
    int n;
    long long c;
    cin >> n >> c;

    map<long long, int> weightsCount;
    for (int i = 0; i < n; ++i) {
        long long w;
        cin >> w;
        weightsCount[w]++;
    }

    long long totalCost = 0;
    long long powerOf2 = 1;
    int destroyedCount = 0;

    while (!weightsCount.empty()) {
        long long threshold = c / powerOf2;
        auto it = weightsCount.upper_bound(threshold);
        if (it != weightsCount.begin()) {
            --it;
            removeBag(weightsCount, it->first);
        } else {
            totalCost++;
            removeBag(weightsCount, weightsCount.begin()->first);
        }

        destroyedCount++;
        if (destroyedCount < n)
            powerOf2 *= 2;
    }

    cout << totalCost << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
