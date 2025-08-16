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

        vector<int> p(n);
        iota(p.begin(), p.end(), 1); // p = [1,2,3,...,n]

        for (int i = 0; i + 1 < n; i += 2) {
            swap(p[i], p[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
