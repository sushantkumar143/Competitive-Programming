#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::string s;
    std::cin >> s;

    x--;

    int days = 0;
    std::vector<char> grid(s.begin(), s.end());

    while (true) {
        days++;

        int l_walls = 0, r_walls = 0;
        int l_empty = 0, r_empty = 0;

        for (int i = 0; i < x; ++i) {
            if (grid[i] == '#') l_walls++;
            else if (grid[i] == '.') l_empty++;
        }
        for (int i = x + 1; i < n; ++i) {
            if (grid[i] == '#') r_walls++;
            else if (grid[i] == '.') r_empty++;
        }

        bool mani_can_build_left = (l_empty > 0);
        bool mani_can_build_right = (r_empty > 0);

        int build_pos = -1;
        if (l_walls == 0 && mani_can_build_left) {
            for (int i = 0; i < x; ++i) if (grid[i] == '.') { build_pos = i; break; }
            if (build_pos != -1) grid[build_pos] = '#';
        } 
        else if (r_walls == 0 && mani_can_build_right) {
            for (int i = n - 1; i > x; --i) if (grid[i] == '.') { build_pos = i; break; }
            if (build_pos != -1) grid[build_pos] = '#';
        } else if (l_walls <= r_walls) {
            if (mani_can_build_left) {
                for (int i = 0; i < x; ++i) if (grid[i] == '.') { build_pos = i; break; }
                if (build_pos != -1) grid[build_pos] = '#';
            } 
            else if (mani_can_build_right) {
                for (int i = x + 1; i < n; ++i) if (grid[i] == '.') { build_pos = i; break; }
                if (build_pos != -1) grid[build_pos] = '#';
            }
        }
        else
        {
            if (mani_can_build_right) {
                for (int i = n - 1; i > x; --i) if (grid[i] == '.') { build_pos = i; break; }
                if (build_pos != -1) grid[build_pos] = '#';
            } 
            else if (mani_can_build_left) {
                for (int i = 0; i < x; ++i) if (grid[i] == '.') { build_pos = i; break; }
                if (build_pos != -1) grid[build_pos] = '#';
            }
        }

        l_walls = 0; r_walls = 0;
        for (int i = 0; i < x; ++i) if (grid[i] == '#') l_walls++;
        for (int i = x + 1; i < n; ++i) if (grid[i] == '#') r_walls++;

        if (l_walls == 0 || r_walls == 0) {
            break;
        }

        if (l_walls <= r_walls)
        {
            int wall_pos = -1;
            for (int i = x - 1; i >= 0; --i) if (grid[i] == '#') { wall_pos = i; break; }
            if (wall_pos != -1) {
                grid[wall_pos] = '.';
                x = wall_pos;
            }
        } 
        else {
            int wall_pos = -1;
            for (int i = x + 1; i < n; ++i) if (grid[i] == '#') { wall_pos = i; break; }
            if (wall_pos != -1) {
                grid[wall_pos] = '.';
                x = wall_pos;
            }
        }
    }
    
    std::cout << days << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}