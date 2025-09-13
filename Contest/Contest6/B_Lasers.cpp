#include <iostream>
using namespace std;

void solve() {
    long long n, m, x, y;
    
    cin >> n >> m >> x >> y;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
    }

    for (int i = 0; i < m; ++i) {
        long long b;
        cin >> b;
    }

    cout << n + m << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

}