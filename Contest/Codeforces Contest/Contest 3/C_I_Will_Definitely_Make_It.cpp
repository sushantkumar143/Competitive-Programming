#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool canReachMaxTower(int n, int start, const vector<int>& heights) {
    int maxHeight = *max_element(heights.begin(), heights.end());
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front(); q.pop();
        if (heights[current] == maxHeight)
            return true;

        // Move left
        if (current - 1 >= 0 && !visited[current - 1] && heights[current - 1] <= heights[start]) {
            visited[current - 1] = true;
            q.push(current - 1);
        }

        // Move right
        if (current + 1 < n && !visited[current + 1] && heights[current + 1] <= heights[start]) {
            visited[current + 1] = true;
            q.push(current + 1);
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> heights(n);
        for (int i = 0; i < n; ++i)
            cin >> heights[i];
        s--; // Convert to 0-based index
        cout << (canReachMaxTower(n, s, heights) ? "YES" : "NO") << endl;
    }
    return 0;
}