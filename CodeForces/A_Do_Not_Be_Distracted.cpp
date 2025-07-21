#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        set<char> seen;
        char last = s[0];
        seen.insert(last);

        bool suspicious = false;
        for (int i = 1; i < n; ++i) {
            if (s[i] != last) {
                if (seen.count(s[i])) {
                    suspicious = true;
                    break;
                }
                seen.insert(s[i]);
                last = s[i];
            }
        }

        cout << (suspicious ? "NO" : "YES") << '\n';
    }

    return 0;
}
