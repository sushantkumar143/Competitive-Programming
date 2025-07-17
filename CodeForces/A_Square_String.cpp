#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int len = s.length();
        if (len % 2 != 0) {
            cout << "NO" << endl;
        } else {
            string firstHalf = s.substr(0, len / 2);
            string secondHalf = s.substr(len / 2);
            if (firstHalf == secondHalf) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
