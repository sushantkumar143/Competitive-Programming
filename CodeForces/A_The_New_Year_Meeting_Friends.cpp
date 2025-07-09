#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int maxi = max({x, y, z});
    int mini = min({x, y, z});
    cout << maxi-mini;
}
