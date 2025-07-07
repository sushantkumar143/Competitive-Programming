#include <bits/stdc++.h>
using namespace std;

bool is_derangement(const vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < a.size(); ++i)
        if (a[i] == b[i])
            return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> sorted = a;
        sort(sorted.begin(), sorted.end());

        vector<int> deranged = sorted;

        // Try to make a derangement by swapping adjacent equal indices
        for (int i = 0; i < n - 1; ++i) {
            if (deranged[i] == sorted[i]) {
                swap(deranged[i], deranged[i + 1]);
            }
        }

        // Final check: if the last element still matches, it's not possible
        if (deranged[n - 1] == sorted[n - 1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << n << "\n";
            for (int x : deranged) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
