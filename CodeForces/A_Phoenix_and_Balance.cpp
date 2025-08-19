#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        long long pile1 = (1LL << n);
        for (int i = 1; i < n/2; i++) {
            pile1 += (1LL << i);
        }
        
        long long pile2 = 0;
        for (int i = n/2; i < n; i++) {
            pile2 += (1LL << i);
        }

        cout << abs(pile1 - pile2) << "\n";
    }
    return 0;
}
