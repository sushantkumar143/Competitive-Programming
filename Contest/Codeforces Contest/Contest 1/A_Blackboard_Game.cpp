#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 4 == 0) cout << "Bob";
        else cout << "Alice";
        cout << '\n';
    }
    return 0;
}
