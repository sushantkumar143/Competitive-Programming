#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        int even_sum = 0, odd_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x % 2 == 0)
                even_sum += x;
            else
                odd_sum += x;
        }

        if (even_sum > odd_sum)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
