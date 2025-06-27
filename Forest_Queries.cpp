#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<vector<char>> arr(n, vector<char>(n));
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int is_star = (arr[i - 1][j - 1] == '*') ? 1 : 0;
            prefix[i][j] = is_star + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = prefix[x2][y2] - prefix[x1 - 1][y2]
                     - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
        cout << result << '\n';
    }

    return 0;
}
