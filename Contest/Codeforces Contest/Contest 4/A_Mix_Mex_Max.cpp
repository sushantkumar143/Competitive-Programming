#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
using namespace std;

int calculate_mex(const std::vector<int>& arr) {
    set<int> s;
    for (int x : arr) {
        if (x != -1) {
            s.insert(x);
        }
    }
    int mex = 0;
    while (s.count(mex)) {
        mex++;
    }
    return mex;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> non_missing_values;
    bool contains_zero = false;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != -1) {
            non_missing_values.insert(a[i]);
            if (a[i] == 0) {
                contains_zero = true;
            }
        }
    }

    if (contains_zero && non_missing_values.size() > 1) {
        cout << "NO\n";
        return;
    }
    if (non_missing_values.size() > 1 && non_missing_values.count(0)) {
        cout << "NO\n";
        return;
    }
    if (non_missing_values.size() > 1) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i <= n - 3; ++i) {
        if (a[i] != -1 && a[i+1] != -1 && a[i+2] != -1) {
            vector<int> window = {a[i], a[i+1], a[i+2]};
            int min_val = *std::min_element(window.begin(), window.end());
            int max_val = *std::max_element(window.begin(), window.end());
            int mex = calculate_mex(window);

            if (mex != max_val - min_val) {
                cout << "NO\n";
                return;
            }
        }
    }

    if (non_missing_values.empty()) {
        cout << "YES\n";
        return;
    }

    if (non_missing_values.size() == 1) {
        int val = *non_missing_values.begin();
        if (val == 0) {
            cout << "NO\n";
        } 
        else {
            cout << "YES\n";
        }
        return;
    }

    if (non_missing_values.size() > 1) {
        cout << "NO\n";
        return;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}