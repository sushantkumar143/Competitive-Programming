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

        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        sort(s.begin(), s.end());

        int min_diff = 1e9;
        for (int i = 0; i < n - 1; ++i) {
            min_diff = min(min_diff, s[i + 1] - s[i]);
        }
        cout << min_diff << "\n";
    }
}
