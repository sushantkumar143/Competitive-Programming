#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> b(n);

    for (int i = 0; i < n; i++) cin >> b[i];

    long long max_b = *max_element(b.begin(), b.end());
    long long min_b = *min_element(b.begin(), b.end());

    long long count_max = count(b.begin(), b.end(), max_b);
    long long count_min = count(b.begin(), b.end(), min_b);

    if (max_b == min_b) {
        long long ways = (1LL * n * (n - 1)) / 2;
        cout << 0 << " " << ways << "\n";
    } 
    else {
        long long diff = max_b - min_b;
        long long ways = count_max * count_min;
        cout << diff << " " << ways << "\n";
    }

    return 0;
}
