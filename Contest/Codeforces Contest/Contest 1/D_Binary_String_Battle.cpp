#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int ones = count(s.begin(), s.end(), '1');

        // Alice wins immediately if she can remove all 1s in one move
        if (ones <= k) {
            cout << "Alice\n";
            continue;
        }

        // Check if there exists a substring of length k with all 1s
        bool bob_can_restore = false;
        int current = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == '1') current++;
        }
        if (current == k) bob_can_restore = true;

        for (int i = k; i < n && !bob_can_restore; i++) {
            if (s[i - k] == '1') current--;
            if (s[i] == '1') current++;
            if (current == k) bob_can_restore = true;
        }

        if (bob_can_restore) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }

    return 0;
}
