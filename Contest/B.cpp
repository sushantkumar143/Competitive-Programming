#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int prefix[MAX][MAX];

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<char>> forest(n + 1, vector<char>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> forest[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int is_tree = (forest[i][j] == '*') ? 1 : 0;
            prefix[i][j] = is_tree + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int trees = prefix[y2][x2]
                  - prefix[y1 - 1][x2]
                  - prefix[y2][x1 - 1]
                  + prefix[y1 - 1][x1 - 1];

        cout << trees << "\n";
    }

    return 0;
}
