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
        int year = stoi(s); // convert string to int

        int r = sqrt(year);
        if (r * r != year) {
            cout << -1 << "\n";
        } else {
            // Just output any valid a, b such that a+b=r
            cout << 0 << " " << r << "\n";
        }
    }
    return 0;
}
