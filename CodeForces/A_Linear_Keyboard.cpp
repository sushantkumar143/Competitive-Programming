#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string keyboard, s;
        cin >> keyboard >> s;

        vector<int> pos(26);
        for (int i = 0; i < 26; i++) {
            pos[keyboard[i] - 'a'] = i + 1; 
        }

        long long time = 0;
        for (int i = 1; i < (int)s.size(); i++) {
            time += abs(pos[s[i] - 'a'] - pos[s[i-1] - 'a']);
        }

        cout << time << "\n";
    }
    return 0;
}
