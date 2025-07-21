#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        int digit = x % 10;
        int len = to_string(x).length();

        int res = (digit - 1) * 10 + len * (len + 1) / 2;
        cout << res << "\n";
    }
    return 0;
}
