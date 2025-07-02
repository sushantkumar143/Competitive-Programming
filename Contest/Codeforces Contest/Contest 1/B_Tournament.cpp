#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void solve() {
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a(n);
    int player_j;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == j - 1) { 
            player_j = a[i];
        }
    }

    int gt = 0;
    int eq = 0; 
    int lt = 0;

    for (int i = 0; i < n; ++i) {
        if (i == j - 1) continue;

        if (a[i] > player_j) {
            gt++;
        } else if (a[i] == player_j) {
            eq++;
        } else {
            lt++;
        }
    }
    int for_j = lt + eq;
    if (gt > 0) {
        for_j += (gt - 1);
    }

    int needed = n - k;

    if (for_j >= needed) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}