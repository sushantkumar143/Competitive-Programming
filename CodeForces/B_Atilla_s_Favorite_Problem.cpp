#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        char max_char = 'a';
        for (char c : s) {
            if (c > max_char)
                max_char = c;
        }

        int alphabet_size = (max_char - 'a') + 1;
        cout << alphabet_size << '\n';
    }

    return 0;
}
