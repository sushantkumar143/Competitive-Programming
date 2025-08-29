#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int l = 1; l < n; l++) {
        if (n % l == 0) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
