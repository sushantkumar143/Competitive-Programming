#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char mirrorChar(char ch) {
    if (ch == 'p') return 'q';
    if (ch == 'q') return 'p';
    return 'w';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        reverse(a.begin(), a.end());
        for (char &ch : a) {
            ch = mirrorChar(ch);
        }
        cout << a << endl;
    }
    return 0;
}
