#include <bits/stdc++.h>
using namespace std;

int main() {
    int y, w;
    cin >> y >> w;

    int maxRoll = max(y, w);
    int favorable = 6 - maxRoll + 1;
    int gcd = __gcd(favorable, 6);

    cout << favorable / gcd << "/" << 6 / gcd << '\n';
    return 0;
}
