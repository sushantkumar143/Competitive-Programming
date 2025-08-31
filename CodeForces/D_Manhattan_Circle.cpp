#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        int minRow = n+1, maxRow = 0;
        int minCol = m+1, maxCol = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#') {
                    minRow = min(minRow, i+1);
                    maxRow = max(maxRow, i+1);
                    minCol = min(minCol, j+1);
                    maxCol = max(maxCol, j+1);
                }
            }
        }

        int centerRow = (minRow + maxRow) / 2;
        int centerCol = (minCol + maxCol) / 2;

        cout << centerRow << " " << centerCol << "\n";
    }
    return 0;
}
