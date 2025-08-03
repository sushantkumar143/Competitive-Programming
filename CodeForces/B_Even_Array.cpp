#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;

        int wrong_even = 0, wrong_odd = 0;

        for(int i = 0; i < n; ++i) {
            if (i % 2 != a[i] % 2) {
                if (i % 2 == 0) wrong_even++;
                else wrong_odd++;
            }
        }

        if (wrong_even == wrong_odd) {
            cout << wrong_even << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}
