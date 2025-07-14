#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int cost1 = n * a;

    int full_packs = n / m;
    int remaining = n % m;

    int cost2 = full_packs * b + min(remaining * a, b);

    cout << min(cost1, cost2) << endl;
    return 0;
}
