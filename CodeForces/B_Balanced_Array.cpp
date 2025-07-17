#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 4 != 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<int> a;
        for (int i = 1; i <= n/2; ++i) {
            a.push_back(2 * i);
        }
        for (int i = 0; i < n/2 - 1; ++i) {
            a.push_back(2 * i + 1);
        }
        int evenSum = 0, oddSum = 0;
        for (int i = 0; i < n/2; ++i) evenSum += a[i];
        for (int i = n/2; i < n - 1; ++i) oddSum += a[i];
        a.push_back(evenSum - oddSum);
        for (int num : a) cout << num << " ";
        cout << "\n";
    }
    return 0;
}
