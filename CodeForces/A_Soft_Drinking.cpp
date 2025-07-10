#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int drink = k*l;
    int tost = drink/nl;
    int lime = c*d;
    int salt = p/np;

    int ans = min({tost, lime, salt})/n;
    cout << ans;
}