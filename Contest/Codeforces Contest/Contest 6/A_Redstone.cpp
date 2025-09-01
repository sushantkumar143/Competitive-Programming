#include <iostream>
#include <vector>
#include <map>

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> counts;
    bool found_duplicate = false;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        counts[a]++;
        if (counts[a] >= 2) {
            found_duplicate = true;
        }
    }

    if (found_duplicate) {
        std::cout << "YES\n";
    } 
    
    
    
    else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }


    
}