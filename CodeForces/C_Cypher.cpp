#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> final_digits(n);
        for (int i = 0; i < n; i++) cin >> final_digits[i];

        vector<int> initial_digits(n);
        for (int i = 0; i < n; i++) {
            int b;
            string moves;
            cin >> b >> moves;

            int shift = 0;
            for (char c : moves) {
                if (c == 'U') shift++;
                else shift--;
            }

            initial_digits[i] = (final_digits[i] - shift) % 10;
            if (initial_digits[i] < 0) initial_digits[i] += 10;
        }

        for (int i = 0; i < n; i++) {
            cout << initial_digits[i] << " ";
        }
        cout << "\n";
    }
}
