#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.empty()) {
            cout << 0 << endl;
            continue;
        }

        int minLength = 1; // first character always counts
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                minLength++; // count only distinct consecutive letters
            }
        }
        cout << minLength << endl;
    }
    return 0;
}
