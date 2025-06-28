#include <bits/stdc++.h>
using namespace std;

long long minTimeToCopy(int n, int x, int y) {
    if (n == 1) return min(x, y); 

    int first = min(x, y);
    n--; 

    long long low = 0, high = 1LL * max(x, y) * n, ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        long long copies = (mid / x) + (mid / y);

        if (copies >= n) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }

    return ans + first;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    cout << minTimeToCopy(n, x, y) << endl;
    return 0;
}
