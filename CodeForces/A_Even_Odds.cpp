#include <iostream>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long num_odds = (n + 1) / 2;

    if (k <= num_odds) {
        cout << 2 * k - 1 << endl;
    } else {
        cout << 2 * (k - num_odds) << endl;
    }

    return 0;
}
