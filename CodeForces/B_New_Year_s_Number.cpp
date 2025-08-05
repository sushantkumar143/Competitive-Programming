#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int r = n % 2020;
        int q = n / 2020;

        if (r <= q) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
