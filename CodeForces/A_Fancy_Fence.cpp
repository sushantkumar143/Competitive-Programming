#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        if (a >= 180) {
            cout << "NO\n";
            continue;
        }
        if (360 % (180 - a) == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
