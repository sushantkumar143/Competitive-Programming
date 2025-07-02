#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int min_val = *min_element(a.begin(), a.end());
        int max_val = *max_element(a.begin(), a.end());
        string ans;
        for (int i = 0; i < n; i++) {
            if (a[i] == a[0] || a[i] == a[n-1] || a[i] == min_val || a[i] == max_val) {
                ans += '1';
            } else {
                ans += '0';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
