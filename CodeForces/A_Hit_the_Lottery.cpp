#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int total = 0;
    int coins[] = {100, 20, 10, 5, 1};

    for (int coin : coins) {
        total += n / coin;
        n %= coin;
    }

    cout << total << endl;
    return 0;
}
