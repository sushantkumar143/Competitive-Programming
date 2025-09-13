#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if (!(cin >> N)) return 0;
    long long best = LLONG_MAX;
    for (int i = 0; i < N; ++i) {
        long long a; cin >> a;
        if (a == 0) {
            cout << 0 << "\n";
            return 0;
        }
        best = min(best, llabs(a));
    }
    cout << best << "\n";
    return 0;
}
