#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> songs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }

    set<int> window;
    int max_len = 0, left = 0;

    for (int right = 0; right < n; ++right) {
        while (window.count(songs[right])) {
            window.erase(songs[left]);
            ++left;
        }
        window.insert(songs[right]);
        max_len = max(max_len, right - left + 1);
    }

    cout << max_len << endl;
    return 0;
}