#include <iostream>
using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;

    if (n % 2 == 0) {
        std::cout << 0 << '\n';
    } 
    else {
        std::cout << x << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

}