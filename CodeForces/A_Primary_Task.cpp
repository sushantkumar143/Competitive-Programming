#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool ok = true;

        if (s.size() < 3 || s.substr(0, 2) != "10") {
            ok = false;
        } 
        else {
            string exp = s.substr(2);
            if (exp[0] == '0') ok = false;
            else {
                int val = stoi(exp);
                if (val < 2) ok = false;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
