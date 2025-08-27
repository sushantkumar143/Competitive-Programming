#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        for(char c = 'a'; c <= 'h'; c++) {
            if(c == s[0]) continue; 
            cout << c << s[1] << '\n';
        }

        for(char r = '1'; r <= '8'; r++) {
            if(r == s[1]) continue;
            cout << s[0] << r << '\n';
        }
    }
}
