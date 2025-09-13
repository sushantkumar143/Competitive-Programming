#include <iostream>
#include <vector>
using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;

    long long flips = 0, pp = 0;

    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;

        long long cp = ((a - b) % 2 + 2) % 2;

        if (cp != pp) {
            flips++;
        }
        pp = cp;
    }

    cout << m - flips << '\n';
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