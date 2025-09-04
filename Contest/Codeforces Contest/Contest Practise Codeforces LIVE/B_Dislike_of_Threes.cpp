#include <bits/stdc++.h>
using namespace std;

bool ok(int x) {
    return (x % 3 != 0 && x % 10 != 3);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int count = 0, num = 1;
        while (true) {
            if (ok(num)) count++;
            if (count == k) {
                cout << num << "\n";
                break;
            }
            num++;
        }
    }
    return 0;
}
