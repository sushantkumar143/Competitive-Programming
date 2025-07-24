#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string p;
        cin >> p;
        char col = p[0];
        char row = p[1];

        for (char r = '1'; r <= '8'; r++) {
            if (r != row) {
                cout << col << r << endl;
            }
        }
        for (char c = 'a'; c <= 'h'; c++) {
            if (c != col) {
                cout << c << row << endl;
            }
        }
    }
}