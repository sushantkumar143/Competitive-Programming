#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    
    if (n == 2) {
        a[0] = -1;
        a[1] = 2;
    } 
    else {
        a[0] = -1;
        a[1] = 3;
        for (int i = 2; i < n; ++i) {
            if (i % 2 == 0) {
                a[i] = -1;
            } else {
                a[i] = 2;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
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
}