#include <iostream>
using namespace std;

void solve() {
    long long x, y, n;
    cin >> x >> y >> n;
    
    long long m = (n - y) / x;
    long long k = m * x + y;
    
    cout << k << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
