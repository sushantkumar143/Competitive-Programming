#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int s1 = max(2 * a, b);
        int s2 = max(a, 2 * b);
        int s3 = max(2 * b, a);
        int s4 = max(b, 2 * a);

        int side = min({s1, s2, s3, s4});
        cout << side * side << '\n';
    }

    return 0;
}
