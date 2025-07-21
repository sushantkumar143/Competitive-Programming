#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int dx[] = {0, 0, -1, 1}; 
const int dy[] = {-1, 1, 0, 0};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& row : grid) cin >> row;

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, INF)));
    deque<tuple<int, int, int>> dq;

    if (grid[n-1][m-1] == '.') {
        cout << -1 << endl;
        return 0;
    }

    dist[n-1][m-1][0] = 0;
    dq.emplace_back(n-1, m-1, 0);

    while (!dq.empty()) {
        auto [x, y, d] = dq.front();
        dq.pop_front();
        int curr_dist = dist[x][y][d];

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '#') {
            if (dist[nx][ny][d] > curr_dist) {
                dist[nx][ny][d] = curr_dist;
                dq.emplace_front(nx, ny, d);
            }
        }

        for (int nd = 0; nd < 4; ++nd) {
            nx = x + dx[nd];
            ny = y + dy[nd];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '#') {
                if (dist[nx][ny][nd] > curr_dist + 1) {
                    dist[nx][ny][nd] = curr_dist + 1;
                    dq.emplace_back(nx, ny, nd);
                }
            }
        }
    }

    int answer = INF;
    for (int d = 0; d < 4; ++d) {
        answer = min(answer, dist[0][0][d]);
    }

    cout << (answer == INF ? -1 : answer) << endl;
    return 0;
}
