#include <bits/stdc++.h>
#include <set>
using namespace std;

set<char> getDigits(int num) {
    set<char> digits;
    string s = to_string(num);
    for (char c : s) {
        digits.insert(c);
    }
    return digits;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        set<char> xDigits = getDigits(x);
        int y = 0;
        while (true) {
            string yStr = to_string(y);
            for (char c : yStr) {
                if (xDigits.count(c)) {
                    cout << y << endl;
                    goto next_test_case;
                }
            }
            y++;
        }
        next_test_case:;
    }
}
