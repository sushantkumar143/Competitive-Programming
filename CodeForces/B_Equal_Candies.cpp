#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int &x : arr) cin >> x;

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        int mini = *min_element(arr.begin(), arr.end());
        long long sm = 0;
        for (int x : arr) sm += x - mini;

        cout << sm << '\n';
    }
    return 0;
}
