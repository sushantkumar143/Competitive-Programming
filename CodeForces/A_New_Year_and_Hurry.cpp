#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int time_left = 240 - k;
    int total = 0;
    int problems = 0;

    for (int i = 1; i <= n; i++) {
        total += 5 * i;
        if (total <= time_left) {
            problems++;
        } else {
            break;
        }
    }

    cout << problems << '\n';
    return 0;
}
