#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long prefixMinSum(const vector<int>& a) {
    int n = a.size();
    int currentMin = a[0];
    long long sum = currentMin;
    for (int i = 1; i < n; ++i) {
        currentMin = min(currentMin, a[i]);
        sum += currentMin;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        // Sort and rotate to get smallest element at front
        vector<int> b = a;
        sort(b.begin(), b.end());
        rotate(b.begin(), b.begin() + 1, b.end());

        cout << prefixMinSum(b) << '\n';
    }

    return 0;
}