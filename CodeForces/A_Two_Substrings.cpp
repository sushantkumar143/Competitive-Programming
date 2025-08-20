#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.find("AB") != string::npos && s.find("BA", s.find("AB") + 2) != string::npos) {
        cout << "YES";
    }
    else if (s.find("BA") != string::npos && s.find("AB", s.find("BA") + 2) != string::npos) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
