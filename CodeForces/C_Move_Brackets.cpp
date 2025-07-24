#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int balance = 0, min_balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else balance--;
            min_balance = min(min_balance, balance);
        }

        cout << -min_balance << '\n';
    }
    return 0;
}
