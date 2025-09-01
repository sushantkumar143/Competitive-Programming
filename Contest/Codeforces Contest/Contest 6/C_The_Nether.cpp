#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    // Phase 1: Find the length of the longest path from each node.
    std::vector<int> L(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cout << "? " << i << " " << n;
        for (int j = 1; j <= n; ++j) {
            std::cout << " " << j;
        }
        std::cout << std::endl;
        std::cin >> L[i];
    }

    // Find the starting node and max length
    int max_len = 0;
    int start_node = -1;
    for (int i = 1; i <= n; ++i) {
        if (L[i] > max_len) {
            max_len = L[i];
            start_node = i;
        }
    }

    // Phase 2: Reconstruct the path
    std::vector<int> path;
    path.push_back(start_node);
    int current_node = start_node;

    while (L[current_node] > 1) {
        int target_len = L[current_node] - 1;
        std::vector<int> candidates;
        for (int i = 1; i <= n; ++i) {
            bool in_path = false;
            for (int p : path) {
                if (p == i) {
                    in_path = true;
                    break;
                }
            }
            if (!in_path && L[i] == target_len) {
                candidates.push_back(i);
            }
        }
        
        int low = 0;
        int high = candidates.size() - 1;
        int next_node = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            std::cout << "? " << current_node << " " << (mid - low + 2);
            std::cout << " " << current_node;
            for (int i = low; i <= mid; ++i) {
                std::cout << " " << candidates[i];
            }
            std::cout << std::endl;

            int res;
            std::cin >> res;
            if (res > 1) { // Found a potential path extender in this range
                high = mid - 1;
            } else { // Not in this range
                low = mid + 1;
            }
        }
        
        // After binary search, low is the index of the next node
        next_node = candidates[low];
        path.push_back(next_node);
        current_node = next_node;
    }

    // Output the final path
    std::cout << "! " << path.size();
    for (int node : path) {
        std::cout << " " << node;
    }
    std::cout << std::endl;
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