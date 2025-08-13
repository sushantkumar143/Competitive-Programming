#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int zeros = count(s.begin(), s.end(), '0');
        int ones = s.size() - zeros;
        
        int moves = min(zeros, ones);
        if (moves % 2 == 1) cout << "DA\n";
        else cout << "NET\n";
    }
    return 0;
}
