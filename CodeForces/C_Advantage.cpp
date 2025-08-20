#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> s(n);
    long long max1 = 0; 
    long long max2 = 0;  

    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        if (s[i] > max1) {
            max2 = max1;
            max1 = s[i];
        } 
        else if (s[i] > max2) {
            max2 = s[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] == max1) {
            std::cout << s[i] - max2 << " ";
        } else {
            std::cout << s[i] - max1 << " ";
        }
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