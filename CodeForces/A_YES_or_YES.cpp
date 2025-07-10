#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        for (char &ch : s) {
            ch = tolower(ch);
        }

        if (s == "yes")
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
