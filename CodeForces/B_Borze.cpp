#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string ans = "";
    int n = s.length();

    for(int i = 0; i < n; ) {
        if(s[i] == '.') {
            ans += '0';
            i++;
        }
        else if(s[i] == '-' && i + 1 < n) {
            if(s[i + 1] == '.') {
                ans += '1';
                i += 2;
            } else if(s[i + 1] == '-') {
                ans += '2';
                i += 2;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
