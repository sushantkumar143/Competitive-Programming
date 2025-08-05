#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPerfectSquare(long long x) {
    long long root = sqrt(x);
    return root * root == x;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            int ai;
            cin >> ai;
            total += ai;
        }
        if (isPerfectSquare(total))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
