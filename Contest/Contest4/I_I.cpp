#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];

    int k;
    cin >> k;

    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b; 

        if (dist[a][b] > c) {
            dist[a][b] = dist[b][a] = c;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int new_dist = min(dist[i][a] + c + dist[b][j],
                                   dist[i][b] + c + dist[a][j]);
                if (dist[i][j] > new_dist)
                    dist[i][j] = new_dist;
            }
        }

        long long total = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                total += dist[i][j];
        
        cout << total << " ";
    }

    return 0;
}
