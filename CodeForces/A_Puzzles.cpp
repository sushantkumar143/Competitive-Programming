#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> pieces(m);
    for (int i = 0; i < m; i++) {
        cin >> pieces[i];
    }

    sort(pieces.begin(), pieces.end());

    int minDiff = INT_MAX;
    for (int i = 0; i <= m - n; i++) {
        int diff = pieces[i + n - 1] - pieces[i];
        minDiff = min(minDiff, diff);
    }

    cout << minDiff << endl;
    return 0;
}
